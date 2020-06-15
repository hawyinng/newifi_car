#!/bin/sh

sp_pid=`ps -ef | grep c_openwrt_newifi | grep -v grep | awk '{print $1}'`
if [ -z "$sp_pid" ];
then
     echo "[ not find c_openwrt_newifi pid ]"
else
     echo "kill processed: $sp_pid "
     kill -9 $sp_pid
fi
