#include "clinet.h"


char *msg2 = "Bye bye!";

int main (int argc, char *argv[]) {
    int bytes_read = 0;
    int sock_fd = 0;
    // int ip = 0;
    char recvBuff[1024];
    struct sockaddr_in client;


    if(argc != 2){
        printf("usage %s ip of server", argv[0]);
        return 1;
    }
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    // if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
    //     printf("Error socket ");
    //     return 1;
    // }
    memset(recvBuff, '0',sizeof(recvBuff));
    memset(&client, '0', sizeof(client));

    client.sin_family = AF_INET;
    client.sin_addr.s_addr = htonl(INADDR_ANY);
    client.sin_port = htons(5000);
    
    if(inet_pton(AF_INET, argv[1], &client.sin_addr) <= 0){
        printf("inet_pton error");
        return 1;
    }
    
    if(connect(sock_fd, (struct sockaddr *) &client, sizeof(client)) < 0 ){
       printf("Error connect failed");
       return 1; 
    }

    while (1) {
        if(send(sock_fd, &msg2, sizeof(msg2), 0) > 0){
            printf("\nHas been sent :%s:\n ", msg2);
        }
        else
        {
            perror("\nsend error\n");
            
        }
        

        bytes_read = recv(sock_fd, &recvBuff, 1025, 0);
        if(bytes_read > 0){
            printf("\n\nreceive goood :%s:\n", recvBuff);
        }
        else
            perror("\n\nreceive errr\n");
        
        // for(int i = 0; i < bytes_read; i++){
        //     printf("%c\n", recvBuff[i]);
        // }
        printf("\n\nONE\n\n\n");
        if(fputs(recvBuff, stdout) == EOF)
        {
            printf("\n Error : Fputs error\n");
            printf("ONE1\n");
        }
    }
    printf("\n\nONE2\n");
}
