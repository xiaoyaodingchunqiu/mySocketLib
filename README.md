# mySocketLib
/*
 * Copyright 2022 ZhangQijun self.
 * Encapsulate the function of socket programming, for easy use
 */

use ag:
./server ip port
./client ip port

This only use tcp communication protocol.
The communication process is as follows:
server: socket---bind---listen---while(1){---accept---recv---send---close---}---close
client: socket----------------------------------connect---send---recv-----------close

1.int InitTcp(const char* ip, int port);
do bind and listen

2.int AcceptTcp(int sfd);
sfd: the old fd
return: the new fd

3.int ConnectTcp(const char* ip, int port);
ip,port: the ip and port that you want to connect
return: the fd that you can use for send.

3.void SingnalHandler(void);
once you use this function, your server will cannot stoped by: "ctrl + C", "ctrl +D"
