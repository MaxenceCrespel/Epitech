/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** connections
*/

#include "../../include/server.h"
#include "../../libs/myteams/logging_client.h"
#include "../../libs/myteams/logging_server.h"

int create_socket(int port_number)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in servaddr;

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port_number);
    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    listen(sockfd, 10);
    return sockfd;
}

void handle_ready_fds(int sockfd, fd_set *readfds, int *max_fd,
client_table_t *client_table)
{
    select_params_t *select_params = malloc(sizeof(select_params_t));
    select_params->max_fd = max_fd;
    select_params->readfds = readfds;
    select_params->sockfd = sockfd;
    fd_set tmp_fds = *readfds;
    int num_ready_fds = select(*max_fd + 1, &tmp_fds, NULL, NULL, NULL);

    if (num_ready_fds == -1)
        exit(84);
    for (int fd = 0; fd <= *max_fd; fd++)
        if (FD_ISSET(fd, &tmp_fds))
            handle_fd(fd, select_params, client_table);
}

void handle_fd(int fd, select_params_t *select_params,
client_table_t *client_table)
{
    if (fd == select_params->sockfd)
        accept_new_client(select_params->sockfd, select_params->readfds,
        select_params->max_fd, client_table);
    else
        handle_client_message(fd, select_params->readfds, client_table);
}

void accept_new_client(int sockfd, fd_set *readfds, int *max_fd,
client_table_t *client_table)
{
    int connfd = accept(sockfd, (struct sockaddr *)NULL, NULL);

    client_info_t *new_client = malloc(sizeof(client_info_t));
    new_client->username = NULL;
    new_client->uuid = NULL;
    client_table->clients[connfd] = new_client;
    FD_SET(connfd, readfds);
    if (connfd > *max_fd)
        *max_fd = connfd;
}

void send_to_multiple_clients(client_table_t *client_table,
char *message_to_send)
{
    for (int i = 0; i < FD_SETSIZE; i++)
        if (client_table->clients[i] != NULL
        && client_table->clients[i]->username != NULL)
            send(i, message_to_send, strlen(message_to_send), 0);
}
