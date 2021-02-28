#pragma once

// ===== includes =====
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <assert.h>
#include <glib/gprintf.h>
#include <glib.h>

#include <arpa/inet.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#include <pthread.h>
#include <signal.h>

#include "cJSON.h"
#include <gtk/gtk.h>

typedef struct s_gtk {
    GtkWidget *client_window;
}   t_gtk;

typedef struct s_client {
    pthread_t connection_th;
    int ac;
    char **av;

    t_gtk *ui;
}   t_client;
