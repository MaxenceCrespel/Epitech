/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** handle_response
*/

#include "../../include/client.h"
#include "../../libs/myteams/logging_client.h"
#include "../../libs/myteams/logging_server.h"

void handle_server_response_bis_bis_bis(char **tokens,
info_t *info_client, char *message)
{
    if (strcmp(tokens[0], "/messages") == 0)
        messages_command(tokens, message);
    else if (strcmp(tokens[0], "/subscribe") == 0)
        printf("/subscribe\n");
    else
        handle_server_response_bis_bis_bis_bis(tokens, info_client);
}

void handle_server_response_bis_bis(char **tokens,
info_t *info_client, char *message)
{
    if (strcmp(tokens[0], "/user") == 0)
        user_command(tokens);
    else if (strcmp(tokens[0], "/send") == 0)
        send_command(tokens, concatenate_tokens(tokens));
    else
        handle_server_response_bis_bis_bis(tokens, info_client, message);
}

void handle_server_response_bis(char **tokens,
info_t *info_client, char *message)
{
    if (strcmp(tokens[0], "/help") == 0)
        usage();
    else if (strcmp(tokens[0], "/users") == 0)
        users_command(tokens);
    else
        handle_server_response_bis_bis(tokens, info_client, message);
}

void handle_server_reponse(char **tokens, info_t *info_client, char *message)
{
    if (strcmp(tokens[0], "/login") == 0)
        login_command(tokens[1], tokens[2], info_client);
    else if (strcmp(tokens[0], "/logout") == 0)
        logout_command(tokens[1], tokens[2], info_client);
    else
        handle_server_response_bis(tokens, info_client, message);
}
