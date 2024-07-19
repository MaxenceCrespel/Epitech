/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** commands_bis
*/

#include "../../include/client.h"
#include "../../libs/myteams/logging_client.h"
#include "../../libs/myteams/logging_server.h"

char *get_uuid_from_username(char *username)
{
    FILE *fp = fopen(".login.txt", "r");;
    char line[100];
    char curr_username[20];
    char curr_uuid[37];
    char status[2];
    char *uuid = NULL;
    int found = 0;

    while (fgets(line, 100, fp)) {
        sscanf(line, "%s %s %s", curr_username, curr_uuid, status);
        if (strcmp(curr_username, username) == 0) {
            uuid = malloc(sizeof(char) * (strlen(curr_uuid) + 1));
            strcpy(uuid, curr_uuid);
            found = 1;
            break;
        }
    }
    fclose(fp);
    return uuid;
}

void split_lines(char *input_str)
{
    char *uuid;
    char *time;
    char *message;
    char *token = strtok(input_str, ";");

    while (token != NULL) {
        uuid = token;
        token = strtok(NULL, ";");
        if (token == NULL)
            break;
        time = token;
        token = strtok(NULL, ";");
        if (token == NULL)
            break;
        message = token;
        client_private_message_print_messages(uuid,
        convert_string_to_time(time), message);
        token = strtok(NULL, ";");
    }
}

void messages_command(char **tokens, char *message)
{
    char *new_message = strdup(message);

    if (strcmp(tokens[1], "unknow") == 0)
        client_error_unknown_user(tokens[2]);
    else {
        clear_first_word(new_message);
        split_lines(new_message);
    }
    free(new_message);
}
