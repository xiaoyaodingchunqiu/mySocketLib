/*
 * Copyright 2022 ZhangQijun self.
 * Encapsulate the function of socket programming, for easy use
 */

#include "TcpNetSocket.h"

int InitTcp(const char* ip, int port) {
    // AF_INET means ipv4, AF_INET6 means ipv6
    // SOCK_STREAM means tcp, SOCK_DGRAM means udp
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sfd == -1) {
        perror("socket error");
        exit(-1);
    }
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(struct sockaddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(ip);

    if(bind(sfd, (struct sockaddr*)&serverAddr, sizeof(struct sockaddr)) == -1) {
        perror("bind error");
        close(sfd);
        exit(-1);
    }

    if(listen(sfd, MAX_CONNECT_NUM) == -1) {
        perror("listen error");
        close(sfd);
        exit(-1);
    }
    return sfd;
}

int AcceptTcp(int sfd) {
    struct sockaddr_in clientAddr; // server accept clint file
    memset(&clientAddr, 0, sizeof(struct sockaddr));
    int addrLen = sizeof(struct sockaddr); // third para of accept need a address
    // new fd for communication, the ip,port are seved in clientAddr
    int newFd = accept(sfd, (struct sockaddr*)&clientAddr, &addrLen);
    if(newFd == -1) {
        perror("accept error");
        close(sfd);
        exit(-1);
    }
    printf("%s %d connect success\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
    return newFd;
}

int ConnectTcp(const char* ip, int port) {
    int sfd = socket(AF_INET,SOCK_STREAM, 0);
    if(sfd == -1) {
        perror("socket error");
        exit(-1);
    }
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(struct sockaddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(ip);

    if(connect(sfd, (struct sockaddr*)&serverAddr, sizeof(struct sockaddr)) == -1) {
        perror("connect error");
        close(sfd);
        exit(-1);
    }

    return sfd;
}

void SingnalHandler(void) {
    sigset_t sigSet;
    sigemptyset(&sigSet);
    sigaddset(&sigSet, SIGINT);
    sigaddset(&sigSet, SIGQUIT);
    sigprocmask(SIG_BLOCK, &sigSet, NULL);
}
