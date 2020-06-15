#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "sys/socket.h"
#include "errno.h"
#include "time.h"
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <sys/signal.h>
#include "stdarg.h"
#include <sys/types.h>
#include <sys/wait.h>

#define MAXLINE 10
#define	SA struct sockaddr

int Socket(int fd, int type, int protocol);
void Bind(int fd, const struct sockaddr *sa, socklen_t salen);
void Listen(int fd, int backlog);
int Accept(int fd, SA *servaddr, socklen_t *n);
ssize_t writen(int fd, const void *vptr, size_t n);
ssize_t readn(int fd, const void *vptr, size_t n);
void err_sys(const char *fmt, ...);
int div_packet(char *buff, char *cmd);
int gethostip(char* localip);
void sig_handler(int signo);

#endif // TCPSERVER_H
