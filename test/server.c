#include "../TcpNetSocket.h"

int main(int argc, char* argv[])
{
    if(argc < 3) {
        printf("use ag: ./server ip port \n");
        exit(-1);
    }
    SingnalHandler();
    int sfd = InitTcp(argv[1], atoi(argv[2]));
    while(1) {
        int newFd = AcceptTcp(sfd);
        char buf[512] = {0};
        if(recv(newFd, buf, sizeof(buf), 0) == -1) {
            perror("recv");
            close(newFd);
            close(sfd);
            exit(-1);
        }
        puts(buf);
        if(send(newFd, "hello world", 12,0) == -1) {
            perror("send");
            close(newFd);
            close(sfd);
            exit(-1);

        }
        close(newFd);
    }
    close(sfd);
    return 0;
}

