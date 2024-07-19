/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** messages_command
*/

#include "../../include/server.h"
#include "../../libs/myteams/logging_client.h"
#include "../../libs/myteams/logging_server.h"

char *find_username(char **tokens)
{
    FILE *login_file = fopen(".login.txt", "r");
    char line[256];

    while (fgets(line, 256, login_file) != NULL) {
        char *username = strtok(line, " ");
        char *uuid = strtok(NULL, " ");
        char *status = strtok(NULL, " ");
        if (uuid != NULL && strcmp(uuid, tokens[1]) == 0) {
            fclose(login_file);
            return strdup(username);
        }
    }
    fclose(login_file);
    return NULL;
}

char *append_with_semicolon(char *str1, char *str2)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char *result = malloc(len1 + len2 + 2);

    strcpy(result, str1);
    result[len1] = ';';
    strcpy(result + len1 + 1, str2);
    result[len1 + len2 + 1] = '\0';
    return result;
}

void send_messages(char **messages, char **tokens,
client_info_t *client_info, int fd)
{
    char *message_to_send = strdup("/messages ");

    for (int i = 0; messages[i] != 0; i++) {
        char *sender = strtok(messages[i], ";");
        char *receiver = strtok(NULL, ";");
        char *mess = strtok(NULL, ";");
        char *time = strtok(NULL, "\n");
        if (strcmp(sender, client_info->username) == 0)
            message_to_send = append_with_semicolon(message_to_send,
            client_info->uuid);
        else
            message_to_send = append_with_semicolon(message_to_send,
            tokens[1]);
        message_to_send = append_with_semicolon(message_to_send, time);
        message_to_send = append_with_semicolon(message_to_send, mess);
    }
    send(fd, message_to_send, strlen(message_to_send), 0);
}

void messages_command(char **tokens, client_info_t *client_info, int fd)
{
    char *username = find_username(tokens);
    char **messages;
    char message_to_send[100];

    if (username != NULL) {
        messages = get_messages(username, client_info->username);
        if (messages != NULL)
            send_messages(messages, tokens, client_info, fd);
        else
            send(fd, "/messages nothing", 19, 0);
        return;
    }
    sprintf(message_to_send, "%s %s ", "/messages unknow", tokens[1]);
    send(fd, message_to_send, strlen(message_to_send), 0);
}
