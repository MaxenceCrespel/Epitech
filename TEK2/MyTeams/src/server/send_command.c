/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** send_command
*/

#include "../../include/server.h"
#include "../../libs/myteams/logging_client.h"
#include "../../libs/myteams/logging_server.h"

char *check_uuid(char **tokens)
{
    FILE *file = fopen(".login.txt", "r");
    char line[100];
    char *username;
    char *user_uuid;

    while (fgets(line, sizeof(line), file) != NULL) {
        username = strtok(line, " ");
        if (username == NULL)
            continue;
        user_uuid = strtok(NULL, " ");
        if (user_uuid == NULL)
            continue;
        if (strcmp(user_uuid, tokens[1]) == 0) {
            fclose(file);
            return strdup(username);
        }
    }
    fclose(file);
    return NULL;
}

int check_client(client_table_t *client_table,
client_info_t *client_info, char **tokens)
{
    for (int i = 0; i < FD_SETSIZE; i++)
        if (client_table->clients[i] != NULL
        && strcmp(client_table->clients[i]->uuid, tokens[1]) == 0)
            return i;
    return 0;
}

void write_in_file(char *username1, char *username2, char *message)
{
    char filename[] = ".messages.txt";
    FILE *file = fopen(filename, "a");
    int conversationExiste = 0;
    char line[100];
    char test1[100];
    char test2[100];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char timestamp[20];

    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm);
    fprintf(file, "%s;%s;%s;%s\n", username1, username2, message, timestamp);
    fclose(file);
}

void send_command(client_info_t *client_info, int fd, char **tokens,
client_table_t *client_table)
{
    char *uuid_exist = check_uuid(tokens);
    int client_exist = check_client(client_table, client_info, tokens);
    char message_to_send[100];

    if (uuid_exist != NULL) {
        write_in_file(client_info->username, uuid_exist, tokens[3]);
        server_event_private_message_sended(client_info->uuid,
        tokens[1], tokens[3]);
        if (client_exist != 0) {
            sprintf(message_to_send, "%s %s %s\n",
            "/send", client_info->uuid, tokens[3]);
            send(client_exist, message_to_send, strlen(message_to_send), 0);
            return;
        }
    } else {
        sprintf(message_to_send, "%s %s %s\n",
        "/send", "unknow", client_info->uuid);
        send(fd, message_to_send, strlen(message_to_send), 0);
    }
}
