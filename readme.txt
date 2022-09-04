配置网卡：ifconfig etho 本地ip最后一个数不同

验证是否连接成功:ping 本地IP地址

传输文件：设置好tftpd32中共享文件夹和IP地址后，在终端中执行tftp -g -l filename 本地IP地址

【需要把mplayer文件下载到开发板的/bin】

音频的暂停,继续,退出：
        暂停：system("killall  -STOP madplay"); //给madplay发送暂停信号
        继续：system("killall  -CONT madplay"); //给madplay发送继续信号
        退出：system("killall  -KILL madplay"); //给madplay发送杀死信号

视频的暂停,继续,退出：
        暂停：system("killall  -STOP mplayer"); //给mplayer发送暂停信号
        继续：system("killall  -CONT mplayer"); //给mplayer发送继续信号
        退出：system("killall  -KILL mplayer"); //给mplayer发送杀死信号

