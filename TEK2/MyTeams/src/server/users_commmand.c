/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** users_commmand
*/

#include "../../include/server.h"
#include "../../libs/myteams/logging_client.h"
#include "../../libs/myteams/logging_server.h"

void print_users(int fd)
{
    FILE *fp = fopen(".login.txt", "r");
    char buffer[1024];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    sprintf(buffer, "/users ");
    while ((read = getline(&line, &len, fp)) != -1)
        strncat(buffer, line, strlen(line));
    fclose(fp);
    if (line)
        free(line);
    send(fd, buffer, strlen(buffer), 0);
}
