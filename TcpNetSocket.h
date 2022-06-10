#ifndef __TCP_NET_SOCKET_H__
#define __TCP_NET_SOCKET_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>

int InitTcp(const char* ip, int port);
int AcceptTcp(int sfd);
int ConnectTcp(const char* ip, int port);
void SingnalHandler(void);


#endif
