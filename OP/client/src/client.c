#include "clinet.h"

void mx_connection_retry_th(GtkWidget *widget, gpointer data) {
    t_client *client = (t_client *)data;

    // gtk_widget_set_sensitive(client->ui->retry_btn, 0);

    if (pthread_create(&client->connection_th, NULL, mx_connect_retry_gtk, (void *)client) != 0) {
        write(STDERR_FILENO, SEND_TH_ERR, sizeof(SEND_TH_ERR));
        exit(1);
    }
}

void ft_init_chat(t_client *client) {
    gtk_init(client->ac, clinet->av);

    // init_window(client);

    mx_connection_retry_th(NULL, (gpointer*)client);

    gtk_main();
}

int main(int ac, char **av) {
    if (ac != 3) {
        printf("ERROR!");
    }

    t_client *client = (t_client *)malloc(sizeof(t_clinet));

    client->gtk = (t_gtk *)malloc(sizeof(t_gtk));
    client->ac = ac;
    clinet->av = av;

    ft_init_chat(client);

    return (0);
}
// #include "chat.h"

// int main (int argc, char *argv[]) {
//     int sock_fd = 0;
//     int ip = 0;
//     char recvBuff[1024];
//     struct sockaddr_in client;
//     if(argc != 2){
//         printf("usage %s ip of server", argv[0]);
//         return 1;
//     }
//     if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
//         printf("Error socket ");
//         return 1;
//     }
//     memset(recvBuff, '0',sizeof(recvBuff));
//     memset(&client, '0', sizeof(client));

//     client.sin_family = AF_INET;
//     client.sin_addr.s_addr = htonl(INADDR_ANY);
//     client.sin_port = htons(5000);
    
//     if(inet_pton(AF_INET, argv[1], &client.sin_addr) <= 0){
//         printf("inet_pton error");
//         return 1;
//     }
    
//     if(connect(sock_fd, (struct sockaddr *) &client, sizeof(client)) < 0 ){
//        printf("Error connect failed");
//        return 1; 
//     }

//     while ((ip = read(sock_fd, recvBuff, sizeof(recvBuff)-1)) > 0)
//     {
//         printf("ONE\n");
//         recvBuff[ip] = 0;
//         if(fputs(recvBuff, stdout) == EOF)
//         {
//             printf("\n Error : Fputs error\n");
//             printf("ONE1\n");
//         }
//     }
//     printf("ONE2\n");
//     if(ip < 0)
//     {
//         printf("ONE3\n");
//         printf("\n Read error \n");
//     }
//     printf("ONE4\n");
// }
