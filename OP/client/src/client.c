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