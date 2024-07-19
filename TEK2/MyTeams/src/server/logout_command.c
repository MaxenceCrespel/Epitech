/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** logout_command
*/

#include "../../include/server.h"
#include "../../libs/myteams/logging_client.h"
#include "../../libs/myteams/logging_server.h"

void update_login_file_status(client_info_t *client_info, FILE *fp)
{
    char line[256];
    char *username;
    char *user_uuid;
    char *status_str;
    int status;

    while (fgets(line, sizeof(line), fp)) {
        username = strtok(line, " ");
        user_uuid = strtok(NULL, " ");
        status_str = strtok(NULL, " ");
        status = atoi(status_str);
        if (strcmp(username, client_info->username) == 0
        && strcmp(user_uuid, client_info->uuid) == 0) {
            server_event_user_logged_out(user_uuid);
            fseek(fp, -strlen(status_str), SEEK_CUR);
            fprintf(fp, "0");
            break;
        }
    }
}

void send_logout_message(client_info_t *client_info,
client_table_t *client_table)
{
    char message_to_send[100];

    sprintf(message_to_send, "%s %s %s", "/logout",
    client_info->username, client_info->uuid);
    send_to_multiple_clients(client_table, message_to_send);
}

void logout_command(client_info_t *client_info, int fd,
client_table_t *client_table)
{
    FILE *fp = fopen(".login.txt", "r+");

    update_login_file_status(client_info, fp);
    send_logout_message(client_info, client_table);
    fclose(fp);
}
