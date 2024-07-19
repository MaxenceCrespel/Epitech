/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** messages_command_bis
*/

#include "../../include/server.h"
#include "../../libs/myteams/logging_client.h"
#include "../../libs/myteams/logging_server.h"

int usernames_match(char *username1, char *username2,
char *sender, char *receiver)
{
    return (strcmp(sender, username1) == 0
    && strcmp(receiver, username2) == 0)
    || (strcmp(sender, username2) == 0
    && strcmp(receiver, username1) == 0);
}

char *read_message(FILE *file, char *line, char *username1, char *username2)
{
    char *dup_line = strdup(line);
    char *sender = strtok(line, ";");
    char *receiver = strtok(NULL, ";");
    char *message = strtok(NULL, ";");
    char *timestamp = strtok(NULL, ";");

    if (usernames_match(username1, username2, sender, receiver))
        return dup_line;
    else {
        free(dup_line);
        return NULL;
    }
}

char **get_messages(char *username1, char *username2)
{
    char **messages = NULL;
    int num_messages = 0;
    char line[256];
    FILE *file = fopen(".messages.txt", "r");
    if (file == NULL)
        return NULL;
    while (fgets(line, sizeof(line), file)) {
        char *message = read_message(file, line, username1, username2);
        if (message != NULL) {
            num_messages++;
            messages = realloc(messages, num_messages * sizeof(char *));
            messages[num_messages - 1] = message;
        }
    }
    fclose(file);
    if (num_messages == 0)
        return NULL;
    messages = realloc(messages, (num_messages + 1) * sizeof(char *));
    messages[num_messages] = NULL;
    return messages;
}
