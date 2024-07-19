/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** main
*/

#include "../../include/server.h"
#include "../../libs/myteams/logging_client.h"
#include "../../libs/myteams/logging_server.h"

void handle_client_message(int fd, fd_set *readfds,
client_table_t *client_table)
{
    char buffer[1024];
    int n = read(fd, buffer, sizeof(buffer));

    if (n == 0) {
        close(fd);
        FD_CLR(fd, readfds);
    } else {
        handle_command(fd, buffer, client_table);
        memset(buffer, 0, sizeof(buffer));
    }
}

void usage(void)
{
    printf("USAGE: ./myteams_server port\n"
    "\n\tport is the port number on which the server socket listens.\n");
}

int run_server(int sockfd)
{
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    int max_fd = sockfd;
    client_table_t client_table;

    memset(&client_table, 0, sizeof(client_table));
    while (1)
        handle_ready_fds(sockfd, &readfds, &max_fd, &client_table);
    close(sockfd);
    return 0;
}

int server(int port_number)
{
    int sockfd = create_socket(port_number);
    char line[100];
    char *username;
    char *uuid;
    char *status;
    FILE *fp = fopen(".login.txt", "r");

    while (fgets(line, sizeof(line), fp)) {
        username = strtok(line, " ");
        uuid = strtok(NULL, " ");
        status = strtok(NULL, "\n");
        replace_char(username, '\b', ' ');
        server_event_user_loaded(uuid, username);
    }
    return run_server(sockfd);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    else if (strcmp(av[1], "-help") == 0)
        usage();
    else
        server(atoi(av[1]));
}
