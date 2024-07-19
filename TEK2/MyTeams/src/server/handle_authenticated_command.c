/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** handle_authenticated_command
*/

#include "../../include/server.h"
#include "../../libs/myteams/logging_client.h"
#include "../../libs/myteams/logging_server.h"

void handle_authenticated_command_bis_bis_bis_bis_bis_bis(int fd,
client_info_t *client_info, client_table_t *client_table, char **tokens)
{
    if (strcmp(tokens[0], "/list") == 0)
        printf("/list\n");
    else if (strcmp(tokens[0], "/info") == 0)
        printf("/info\n");
    else
        send(fd, "Wrong command", 14, 0);
}

void handle_authenticated_command_bis_bis_bis_bis_bis(int fd,
client_info_t *client_info, client_table_t *client_table, char **tokens)
{
    if (strcmp(tokens[0], "/use") == 0)
        printf("/use\n");
    else if (strcmp(tokens[0], "/create") == 0)
        printf("/create\n");
    else
        handle_authenticated_command_bis_bis_bis_bis_bis_bis(fd,
        client_info, client_table, tokens);
}

void handle_authenticated_command_bis_bis_bis_bis(int fd,
client_info_t *client_info, client_table_t *client_table, char **tokens)
{
    if (strcmp(tokens[0], "/subscribed") == 0)
        printf("/subscribed\n");
    else if (strcmp(tokens[0], "/unsubscribe") == 0)
        printf("/unsubscribe\n");
    else
        handle_authenticated_command_bis_bis_bis_bis_bis(fd,
        client_info, client_table, tokens);
}

void handle_authenticated_command_bis_bis_bis(int fd,
client_info_t *client_info, client_table_t *client_table, char **tokens)
{
    if (strcmp(tokens[0], "/messages") == 0)
        messages_command(tokens, client_info, fd);
    else if (strcmp(tokens[0], "/subscribe") == 0)
        printf("/subscribe\n");
    else
        handle_authenticated_command_bis_bis_bis_bis(fd, client_info,
        client_table, tokens);
}

void handle_authenticated_command_bis_bis(int fd, client_info_t *client_info,
client_table_t *client_table, char **tokens)
{
    if (strcmp(tokens[0], "/user") == 0)
        user_command(client_info, fd, tokens[1]);
    else if (strcmp(tokens[0], "/send") == 0)
        send_command(client_info, fd, tokens, client_table);
    else
        handle_authenticated_command_bis_bis_bis(fd, client_info,
        client_table, tokens);
}
