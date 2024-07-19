/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** list_commands
*/

#include "../../include/server.h"
#include "../../libs/myteams/logging_client.h"
#include "../../libs/myteams/logging_server.h"

void handle_unauthenticated_command(int fd, client_info_t *client_info,
client_table_t *client_table, char **tokens)
{
    if (strcmp(tokens[0], "/login") == 0 && tokens[1] != NULL)
        login_command(client_info, tokens, fd, client_table);
    else if (strcmp(tokens[0], "/logout") == 0
    || strcmp(tokens[0], "/help") == 0
    || strcmp(tokens[0], "/users") == 0 || strcmp(tokens[0], "/send") == 0
    || strcmp(tokens[0], "/user") == 0 || strcmp(tokens[0], "/messages") == 0
    || strcmp(tokens[0], "/subscribe") == 0
    || strcmp(tokens[0], "/unsubscribe") == 0
    || strcmp(tokens[0], "/subscribed") == 0
    || strcmp(tokens[0], "/create") == 0 || strcmp(tokens[0], "/list") == 0
    || strcmp(tokens[0], "/use") == 0 || strcmp(tokens[0], "/info") == 0)
        send(fd, "Not login", 10, 0);
    else
        send(fd, "Wrong command", 14, 0);
}

void handle_authenticated_command_bis(int fd, client_info_t *client_info,
client_table_t *client_table, char **tokens)
{
    if (strcmp(tokens[0], "/help") == 0)
        send(fd, "/help", 6, 0);
    else if (strcmp(tokens[0], "/users") == 0)
        print_users(fd);
    else
        handle_authenticated_command_bis_bis(fd, client_info,
        client_table, tokens);
}

void handle_authenticated_command(int fd, client_info_t *client_info,
client_table_t *client_table, char **tokens)
{
    if (strcmp(tokens[0], "/logout") == 0)
        logout_command(client_info, fd, client_table);
    else
        handle_authenticated_command_bis(fd, client_info, client_table,
        tokens);
}

int handle_command(int fd, char *str, client_table_t *client_table)
{
    int num_tokens;
    char **tokens = split_string(str, "\t\"\n", &num_tokens);
    client_info_t *client_info = client_table->clients[fd];

    remove_spaces(tokens[0]);
    if (client_info->username == NULL && client_info->uuid == NULL)
        handle_unauthenticated_command(fd, client_info, client_table, tokens);
    else if (client_info->username != NULL && client_info->uuid != NULL)
        handle_authenticated_command(fd, client_info, client_table, tokens);
    for (int i = 0; i < num_tokens; i++)
        free(tokens[i]);
    free(tokens);
    return 1;
}
