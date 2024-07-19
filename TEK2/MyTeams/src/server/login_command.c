/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** login_command
*/

#include "../../include/server.h"
#include "../../libs/myteams/logging_client.h"
#include "../../libs/myteams/logging_server.h"

FILE *open_login_file(const char *filename)
{
    if (access(filename, F_OK) != -1)
        return fopen(filename, "r+");
    else
        return fopen(filename, "a");
}

int search_user(FILE *fp, const char *username, const char *user_uuid,
client_info_t *client_info)
{
    char line[100];

    while (fgets(line, sizeof(line), fp)) {
        char *tok = strtok(line, " ");
        char *uuid_str = strtok(NULL, " \n");
        char *status_str = strtok(NULL, " \n");
        char uuid[37];
        uuid_unparse(uuid_str, uuid);
        int status = atoi(status_str);
        if (strcmp(tok, username) == 0) {
            client_info->username = strdup(username);
            client_info->uuid = strdup(user_uuid);
            fseek(fp, -1 * strlen(status_str) - 38, SEEK_CUR);
            fprintf(fp, "%s 1", user_uuid);
            server_event_user_logged_in(user_uuid);
            return 1;
        }
    }
    return 0;
}

void create_user(FILE *fp, char *username, const char *user_uuid,
client_info_t *client_info)
{
    fprintf(fp, "%s %s 1\n", username, user_uuid);
    client_info->username = strdup(username);
    client_info->uuid = strdup(user_uuid);
    replace_char(username, '\b', ' ');
    server_event_user_created(user_uuid, username);
    server_event_user_logged_in(user_uuid);
}

void replace_char(char *str, char char1, char char2)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == char1)
            str[i] = char2;
        i++;
    }
}

int login_command(client_info_t *client_info, char **tokens, int fd,
client_table_t *client_table)
{
    uuid_t *uuid;
    char user_uuid[37];
    char message_to_send[100];
    FILE *fp;
    int found_user;

    replace_char(tokens[1], ' ', '\b');
    uuid_generate_random(*uuid);
    uuid_unparse(*uuid, user_uuid);
    sprintf(message_to_send, "%s %s %s", tokens[0], tokens[1], user_uuid);
    fp = open_login_file(".login.txt");
    found_user = search_user(fp, tokens[1], user_uuid, client_info);
    if (!found_user)
        create_user(fp, tokens[1], user_uuid, client_info);
    fclose(fp);
    send_to_multiple_clients(client_table, message_to_send);
}
