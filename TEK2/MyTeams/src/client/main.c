/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** main
*/

#include "../../include/client.h"
#include "../../libs/myteams/logging_client.h"
#include "../../libs/myteams/logging_server.h"

void error_exit(void)
{
    exit(84);
}

int client(char *server_ip, int server_port)
{
    int sockfd = create_socket();
    struct sockaddr_in server_addr;

    set_server_address(&server_addr, server_ip, server_port);
    connect_to_server(sockfd, &server_addr);
    send_messages(sockfd);
    close(sockfd);
    return 0;
}

void usage(void)
{
    printf("USAGE: ./myteams_cli ip port\n"
    "\tip is the server ip address on which the server socket listens\n"
    "\tport is the port number on which the server socket listens\n");
}

int main(int ac, char **av)
{
    if (ac != 3)
        return 84;
    else if (strcmp(av[1], "-help") == 0)
        usage();
    else
        client(av[1], atoi(av[2]));
}
