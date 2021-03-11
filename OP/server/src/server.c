#include "server.h"


char *msg2 = "Zaebal";
int main () {

    int bytes_read;
    int port = 0;
    // time_t time;
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
        send(5000, &msg2, strlen(msg2), 0);
        // snprintf(sendBuff, sizeof(sendBuff), "%.24s\r\n", ctime(&time));
        // write(port, sendBuff, strlen(sendBuff));   
        bytes_read = recv(port, &sendBuff, 1025, 0);
        if(bytes_read < 0)
        {
            perror("An error occured during the receive procedure\n");
        }
        else
        {
            for(int i = 0; i < bytes_read; i++){
                printf("%c\n", sendBuff[i]);

            }
        }
        
        // printf("%zd\n", recv(listen_fd, sendBuff, 1025, 0));
        // printf("%s", sendBuff);
        printf("start2\n");
        close(port);
        sleep(1);
    }

}
