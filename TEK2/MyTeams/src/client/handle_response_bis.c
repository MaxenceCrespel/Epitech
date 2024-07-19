/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** handle_response_bis
*/

#include "../../include/client.h"
#include "../../libs/myteams/logging_client.h"
#include "../../libs/myteams/logging_server.h"

void handle_server_response_bis_bis_bis_bis_bis_bis_bis(char **tokens,
info_t *info_client)
{
    if (strcmp(tokens[0], "Not") == 0)
        client_error_unauthorized();
    else
        printf("Wrong command and not login\n");
}

void handle_server_response_bis_bis_bis_bis_bis_bis(char **tokens,
info_t *info_client)
{
    if (strcmp(tokens[0], "/list") == 0)
        printf("/list\n");
    else if (strcmp(tokens[0], "/info") == 0)
        printf("/info\n");
    else
        handle_server_response_bis_bis_bis_bis_bis_bis_bis(tokens,
        info_client);
}

void handle_server_response_bis_bis_bis_bis_bis(char **tokens,
info_t *info_client)
{
    if (strcmp(tokens[0], "/use") == 0)
        printf("/use\n");
    else if (strcmp(tokens[0], "/create") == 0)
        printf("/create\n");
    else
        handle_server_response_bis_bis_bis_bis_bis_bis(tokens, info_client);
}

void handle_server_response_bis_bis_bis_bis(char **tokens, info_t *info_client)
{
    if (strcmp(tokens[0], "/subscribed") == 0)
        printf("/subscribed\n");
    else if (strcmp(tokens[0], "/unsubscribe") == 0)
        printf("/unsubscribe\n");
    else
        handle_server_response_bis_bis_bis_bis_bis(tokens, info_client);
}
