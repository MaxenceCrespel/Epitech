/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** parse_commands
*/

#include "../../include/server.h"
#include "../../libs/myteams/logging_client.h"
#include "../../libs/myteams/logging_server.h"

void remove_spaces(char *str)
{
    int i;
    int j;

    for (i = 0, j = 0; str[i]; i++)
        if (str[i] != ' ')
            str[j++] = str[i];
    str[j] = '\0';
}

char **split_string(char *input_str, const char *delimiter, int *num_tokens)
{
    char **tokens = NULL;
    char *token = strtok(input_str, delimiter);
    int num_tokens_allocated = 0;
    int len;

    *num_tokens = 0;
    while (token != NULL) {
        if (*num_tokens >= num_tokens_allocated) {
            num_tokens_allocated += 10;
            tokens = realloc(tokens, num_tokens_allocated * sizeof(char *));
        }
        tokens[*num_tokens] = malloc((strlen(token) + 1) * sizeof(char));
        strcpy(tokens[*num_tokens], token);
        *num_tokens += 1;
        token = strtok(NULL, delimiter);
    }
    if (is_last_char_delimiter(input_str, delimiter))
        add_null_token(tokens, num_tokens, num_tokens_allocated);
    return tokens;
}

int is_last_char_delimiter(char *str, const char *delimiter)
{
    int len = strlen(str);

    return len > 0 && str[len - 1] == delimiter[0];
}

void add_null_token(char **tokens, int *num_tokens, int num_tokens_allocated)
{
    if (*num_tokens >= num_tokens_allocated) {
        num_tokens_allocated += 1;
        tokens = realloc(tokens, num_tokens_allocated * sizeof(char *));
    }
    tokens[*num_tokens] = NULL;
    *num_tokens += 1;
}
