/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** server_connection
*/

#include "../../include/client.h"
#include "../../libs/myteams/logging_client.h"
#include "../../libs/myteams/logging_server.h"

int create_socket(void)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        error_exit();
    return sockfd;
}

void set_server_address(struct sockaddr_in *server_addr, char *server_ip,
int server_port)
{
    memset(server_addr, 0, sizeof(*server_addr));
    server_addr->sin_family = AF_INET;
    server_addr->sin_addr.s_addr = inet_addr(server_ip);
    server_addr->sin_port = htons(server_port);
}

void connect_to_server(int sockfd, struct sockaddr_in *server_addr)
{
    if (connect(sockfd, (struct sockaddr *)server_addr,
    sizeof(*server_addr)) < 0)
        error_exit();
}
