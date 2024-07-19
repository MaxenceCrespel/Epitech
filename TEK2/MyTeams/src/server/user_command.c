/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** user_command
*/

#include "../../include/server.h"
#include "../../libs/myteams/logging_client.h"
#include "../../libs/myteams/logging_server.h"

int check_user(char *line, char *message_to_send, char *uuid, int fd)
{
    char *username = strtok(line, " ");
    char *user_uuid = strtok(NULL, " ");

    if (username != NULL && user_uuid != NULL)
        if (strcmp(uuid, user_uuid) == 0) {
            send(fd, message_to_send, strlen(message_to_send), 0);
            return 1;
        }
    return 0;
}

void user_command(client_info_t *client, int fd, char *uuid)
{
    FILE *fp;
    char line[1024];
    char message_to_send[100];

    fp = fopen(".login.txt", "r");
    while (fgets(line, 1024, fp) != NULL) {
        sprintf(message_to_send, "%s %s", "/user", line);
        if (check_user(line, message_to_send, uuid, fd) == 1) {
            fclose(fp);
            return;
        }
    }
    sprintf(message_to_send, "%s %s %s", "/user", uuid, "unknow");
    send(fd, message_to_send, strlen(message_to_send), 0);
    fclose(fp);
}
