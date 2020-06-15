# newifi_car
# 源程序编译说明
1. /Arduino/sketch_jun12c/sketch_jun12c.ino 编译上传Arduino UNO R3开发板。
2. /c_openwrt_newifi 源文件在Ubuntu_16.04 Linux系统下使用OpenWrt-Toolchain-ramips-mt7621_gcc-5.3.0_musl-1.1.16.Linux-x86_64交叉编译通过，c_openwrt_newifi可执行文件server端上传newifi路由器使用。
3. /ClientCar_wifi_car 源文件使用Qt5.14.2编译通过，android-build-debug.apk上传手机使用。ClientCar.app手机控制端。

![image](https://github.com/hawyinng/newifi_car/blob/master/images/IMG_12.jpg) ![image](https://github.com/hawyinng/newifi_car/blob/master/images/IMG_7.jpg) ![image](https://github.com/hawyinng/newifi_car/blob/master/images/newifi_5.PNG)

# 安装程序说明
1.WinSCP远程登录newifi路由器“192.168.0.1”，SCP协议连接。用户名“root”，密码“password”。
![image](https://github.com/hawyinng/newifi_car/blob/master/images/newifi_3.PNG)

2.解压c_openwrt_newifi.zip，上传程序c_openwrt_newifi到“/root”目录下。
![image](https://github.com/hawyinng/newifi_car/blob/master/images/newifi_2.PNG)

3.SSH连接newifi路由器，输入命令“chmod +x c_openwrt_newifi”。c_openwrt_newifi文件，“属性”权限直接打勾也行。
![image](https://github.com/hawyinng/newifi_car/blob/master/images/newifi_4.PNG)

# newifi路由器安装USB串口驱动：
1.WinSCP远程连接newifi路由器，上传5个ipk驱动到/tmp目录安装。
![image](https://github.com/hawyinng/newifi_car/blob/master/images/newifi_6.PNG)

2.SSH连接newifi路由器，输入以下命令：
opkg install /tmp/kmod-usb-acm_4.14.172-1_mipsel_24kc.ipk --nodeps

opkg install /tmp/kmod-usb-ohci_4.14.172-1_mipsel_24kc.ipk --nodeps

opkg install /tmp/kmod-usb2_4.14.172-1_mipsel_24kc.ipk --nodeps

opkg install /tmp/kmod-usb-serial_4.14.172-1_mipsel_24kc.ipk --nodeps

opkg install /tmp/kmod-usb-serial-ftdi_4.14.172-1_mipsel_24kc.ipk --nodeps

驱动安装完成，reboot路由器。
 
![image](https://github.com/hawyinng/newifi_car/blob/master/images/newifi_7.PNG)
![image](https://github.com/hawyinng/newifi_car/blob/master/images/newifi_8.PNG)


Arduino USB数据线插入路由器，/dev目录下有ttyASM0(或者ttyASM1)接口（/dev/ttyASM0或者/dev/ttyASM1）-->> Arduino开发板连接完成。
PS: /dev目录下有ttyASM0(或者ttyASM1)接口，连上小车没反应，热插拔几下USB接口，重新运行c_openwrt_newifi服务端。
![image](https://github.com/hawyinng/newifi_car/blob/master/images/newifi_9.PNG)。

