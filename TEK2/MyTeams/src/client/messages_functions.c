/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** messages_functions
*/

#include "../../include/client.h"
#include "../../libs/myteams/logging_client.h"
#include "../../libs/myteams/logging_server.h"

void setup_fd_set(int sockfd, fd_set* readfds)
{
    FD_ZERO(readfds);
    FD_SET(sockfd, readfds);
    FD_SET(STDIN_FILENO, readfds);
}

void wait_for_activity(int sockfd, fd_set* readfds)
{
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    if (select(sockfd + 1, readfds, NULL, NULL, &tv) < 0)
        error_exit();
}

void send_input(int sockfd, char *send_message)
{
    fgets(send_message, MAX_MSG_LEN, stdin);
    if (send(sockfd, send_message, strlen(send_message), 0) < 0)
        error_exit();
}

void receive_message_func(int sockfd, char *receive_message,
info_t *info_client)
{
    int n = recv(sockfd, receive_message, MAX_MSG_LEN - 1, 0);
    int num_tokens;
    char **tokens;
    char *message = strdup(receive_message);

    if (n <= 0) {
        close(sockfd);
        error_exit();
    }
    receive_message[n] = '\0';
    tokens = split_string(receive_message, " \t\n", &num_tokens);
    handle_server_reponse(tokens, info_client, message);
    for (int i = 0; i < num_tokens; i++)
        free(tokens[i]);
    free(tokens);
    free(message);
}

void send_messages(int sockfd)
{
    char send_message[MAX_MSG_LEN];
    char receive_message[MAX_MSG_LEN];
    fd_set readfds;
    info_t *info_client = malloc(sizeof(info_t));

    while (1) {
        setup_fd_set(sockfd, &readfds);
        wait_for_activity(sockfd, &readfds);
        if (FD_ISSET(STDIN_FILENO, &readfds))
            send_input(sockfd, send_message);
        if (FD_ISSET(sockfd, &readfds))
            receive_message_func(sockfd, receive_message, info_client);
    }
}
