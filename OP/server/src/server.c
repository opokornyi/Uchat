#include "server.h"

int main (int argc, char *argv[]) {


    int port = 0;
    time_t time;
    char sendBuff[1025];
    int listen_fd = 0;
    struct sockaddr_in addr;
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    memset(sendBuff, '0', sizeof(sendBuff));
    memset(&addr, '0', sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(5000);
    bind(listen_fd, (struct sockaddr *) &addr, sizeof(addr));
    listen(listen_fd, 10);


    while(1){
        printf("start1\n");
        port = accept(listen_fd, (struct sockaddr *) NULL, NULL);
        snprintf(sendBuff, sizeof(sendBuff), "%s", ctime(&time));
        write(port, sendBuff, strlen(sendBuff));   
        printf("start2\n");
        close(port);
        sleep(1);
    }

}