/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** commands
*/

#include "../../include/client.h"
#include "../../libs/myteams/logging_client.h"
#include "../../libs/myteams/logging_server.h"

void login_command(char *str, char *uuid_str, info_t *info_client)
{
    if (info_client->username == NULL) {
        info_client->username = strdup(str);
        info_client->uuid = strdup(uuid_str);
    }
    replace_char(str, '\b', ' ');
    client_event_logged_in(uuid_str, str);
}

void logout_command(char *str, char *uuid_str, info_t *info_client)
{
    if (strcmp(info_client->username, str) == 0) {
        replace_char(str, '\b', ' ');
        client_event_logged_out(uuid_str, str);
        free(info_client->username);
        free(info_client->uuid);
        free(info_client);
        exit(0);
    }
    replace_char(str, '\b', ' ');
    client_event_logged_out(uuid_str, str);
}

void user_command(char **tokens)
{
    if (strcmp(tokens[2], "unknow") == 0)
        client_error_unknown_user(tokens[1]);
    else {
        replace_char(tokens[1], '\b', ' ');
        client_print_user(tokens[2], tokens[1], atoi(tokens[3]));
    }
}

void users_command(char **tokens)
{
    for (int i = 1; tokens[i] != NULL; i += 3) {
        replace_char(tokens[i], '\b', ' ');
        client_print_users(tokens[i + 1], tokens[i], atoi(tokens[i + 2]));
    }
}

void send_command(char **tokens, char *message)
{
    if (strcmp(tokens[1], "unknow") == 0)
        client_error_unknown_user(tokens[2]);
    else
        client_event_private_message_received(tokens[1], message);
}
