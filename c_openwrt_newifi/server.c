#include "server.h"
#include "port.h"

#define ETH_NAME "br-lan"

extern int Socket(int fd, int type, int protocol);
extern void Bind(int fd, const struct sockaddr *sa, socklen_t salen);
extern void Listen(int fd, int backlog);
extern int Accept(int fd, SA *servaddr, socklen_t *n);
extern ssize_t writen(int fd, const void *vptr, size_t n);
extern ssize_t readn(int fd, const void *vptr, size_t n);
extern int div_packet(char *buff, char *cmd);
extern int init_port();
extern int send_port(int fd, char *cmd);
extern int gethostip(char* localip);
extern void sig_handler(int signo);

int main()
{
    int listenfd, connfd;
    pid_t pid;
    socklen_t len;
    struct sockaddr_in servaddr, cliaddr;  //服务器，客户端ip地址结构
    char buff[MAXLINE];

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    char localip[11];
	gethostip(localip);
    servaddr.sin_addr.s_addr = inet_addr(localip);
	//servaddr.sin_addr.s_addr = inet_addr("192.168.0.1");
    servaddr.sin_port = htons(8989);

    Bind(listenfd, (SA *)&servaddr, sizeof(servaddr));

    Listen(listenfd, 5);
    fprintf(stderr, "listen success\n");

    //打开串口
    int fd = init_port();

    while(1)
    {
        memset(buff, 0x00, sizeof(buff));
        len = sizeof(cliaddr);
        //阻塞accept
        connfd = accept(listenfd, (SA *)&cliaddr, &len);
        if(connfd < 0)
        {
            //系统中断的调用
            if(errno == EINTR)
                continue;
            else
            {
                perror("accept error!");
                return (-1);
            }
        }
        fprintf(stderr, "connect from %s, port %d\n",
                inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        //fork函数的并发服务器
        //开启子进程服务客户,已打开描述符在父子进程间共享
        //子进程描述符为父进程的副本
        //signal(SIGCHLD, sig_handler);
        signal(SIGCHLD, SIG_IGN);
        if((pid = fork()) == 0)
        {
            close(listenfd);  //关闭子进程的监听套接字
            //阻塞,接收客户发送的数据
            while(readn(connfd, buff, sizeof(buff)) > 0)
            {
                fprintf(stderr, "client fd: %d\n", connfd);
                fprintf(stderr, "server recv: %s\n", buff);
                close(listenfd);

                //解上传数据包，并发送数据到串口
                char cmd[2];
                memset(cmd, 0x00, sizeof(cmd));
                if(div_packet(buff, cmd)){
                	if(send_port(fd, cmd) >= 0)
					{
						memset(buff, 0x00, sizeof(buff));
						snprintf(buff, sizeof(buff), "recv ok.\n");
						//回传数据给客户;
						writen(connfd, buff, sizeof(buff));
						fprintf(stderr, "server send ok.\n\n");
					}
					else{
						close(connfd);
					}
                }
            }
            exit(0);  //进程终止，关闭子进程所有已打开的描述符
        }

        //客户断开链接,关闭链接套接字
        close(connfd);
    }

   return 0;
}

int Socket(int fd, int type, int protocol)
{
    int n;

    if((n = socket(fd, type, protocol)) < 0)
        perror("socket error");

    return n;
}

void Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
    if (bind(fd, sa, salen) < 0)
       perror("bind error");
    else
       fprintf(stderr, "bind success\n");
}

void Listen(int fd, int backlog)
{
    if (listen(fd, backlog) < 0)
        perror("listen error");
}

int Accept(int fd, SA *addr, socklen_t *n)
{
    int connfd;

    if((connfd = accept(fd, addr, n))< 0)
    {
        perror("accept error");
        return -1;
    }
    else
        return connfd;
}

/* Write "n" bytes to a descriptor. */
ssize_t writen(int fd, const void *vptr, size_t n)
{
    size_t		nleft;
    ssize_t		nwritten;
    const char	*ptr;

    ptr = (char *)vptr;
    nleft = n;
    while (nleft > 0) {
        if ( (nwritten = write(fd, ptr, nleft)) <= 0) {
            if (nwritten < 0 && errno == EINTR)
                nwritten = 0;		/* and call write() again */
            else
                return(-1);			/* error */
        }

        nleft -= nwritten;
        ptr   += nwritten;
    }
    return(n);
}
/* end writen */

ssize_t readn(int fd, const void *vptr, size_t n)
{
    size_t	nleft;
    ssize_t	nread;
    char	*ptr;

    ptr = (char *)vptr;
    nleft = n;
    while (nleft > 0) {
        if ( (nread = read(fd, ptr, nleft)) < 0) {
            if (errno == EINTR)
                nread = 0;		/* and call read() again */
            else
                return(-1);
        } else if (nread == 0)
            break;				/* EOF */

        nleft -= nread;
        ptr   += nread;
    }
    return(n - nleft);		/* return >= 0 */
}
/* end readn */

int div_packet(char *buff, char *cmd)
{
    char *ptr;

    ptr = buff;
    ptr += 4;

    memcpy(cmd, ptr, 1);
    if(cmd[0] == 0 || cmd[0] == '\0'){
    	return 0;
    }

    cmd[1] = '\0';
    fprintf(stderr, "div_packet cmd: %s\n", cmd);

    return 1;
}

int gethostip(char* localip)
{
	FILE *fp;
	char buf[256] = {0};
	char command[256] = {0};
	//char *fmt = "ifconfig %s|sed -n '2p'|sed -n 's#^.*dr:##gp'|sed -n 's#B.*$##gp'";
	char *fmt = "ifconfig %s|grep 'inet addr'|awk '{ print $2}' | awk -F: '{print $2}'";

	snprintf(command, sizeof(command), fmt, ETH_NAME);
	if((fp = popen(command, "r")) == NULL)
	{
		perror("Fail to popen\n");
		return -1;
	}
	while(fgets(buf, sizeof(buf), fp) != NULL)
	{
		printf("local ip: %s\n", buf);
	}

	memcpy(localip, buf, 11);

	pclose(fp);
	return 0;
}

void sig_handler(int signo)
{
    printf("child process %d stop.\n", signo);
    int pid = -1;
    int stat;
    while( pid=waitpid(0, &stat, WNOHANG) );
}

