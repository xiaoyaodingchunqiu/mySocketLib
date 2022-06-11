/*
 * Copyright 2022 ZhangQijun self.
 * Encapsulate the function of socket programming, for easy use
 */

#include "../TcpNetSocket.h"

int main(int argc, char* argv[])
{
    if(argc < 3) {
        printf("use ag: ./client ip port\n");
        exit(-1);
    }
    int sfd = ConnectTcp(argv[1], atoi(argv[2]));
    char buf[512] = {0};
    send(sfd, "hello", 6, 0);
    recv(sfd, buf, sizeof(buf), 0);
    puts(buf);
    close(sfd);
    return 0;
}

