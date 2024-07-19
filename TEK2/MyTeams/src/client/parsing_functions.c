/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** parsing_functions
*/

#include "../../include/client.h"
#include "../../libs/myteams/logging_client.h"
#include "../../libs/myteams/logging_server.h"

void replace_char(char *str, char char1, char char2)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == char1) {
            str[i] = char2;
        }
        i++;
    }
}

char **split_string(char *input_str, const char *delimeter, int *num_tokens)
{
    char **tokens = NULL;
    char *token = strtok(input_str, delimeter);
    int num_tokens_allocated = 0;

    *num_tokens = 0;
    while (token != NULL) {
        if (*num_tokens >= num_tokens_allocated) {
            num_tokens_allocated = num_tokens_allocated + 10;
            tokens = realloc(tokens, num_tokens_allocated * sizeof(char *));
        }
        tokens[*num_tokens] = malloc((strlen(token) + 1) * sizeof(char));
        strcpy(tokens[*num_tokens], token);
        *num_tokens = *num_tokens + 1;
        token = strtok(NULL, delimeter);
    }
    return tokens;
}

char *concatenate_tokens(char **tokens)
{
    int i;
    int len = 0;
    int total_len = 0;
    char *result;

    for (i = 2; tokens[i] != NULL; i++) {
        len = strlen(tokens[i]);
        total_len += len + 1;
    }
    result = (char *)malloc(total_len * sizeof(char));
    for (i = 2; tokens[i] != NULL; i++) {
        strcat(result, tokens[i]);
        strcat(result, " ");
    }
    result[total_len - 1] = '\0';
    return result;
}

void clear_first_word(char *str)
{
    int i = 0;
    int len = strlen(str);

    while (isspace(str[i]) && i < len)
        i++;
    while (!isspace(str[i]) && i < len)
        i++;
    i++;
    memmove(str, str + i, len - i + 1);
}

time_t convert_string_to_time(char *str)
{
    struct tm timeinfo;
    time_t result;

    memset(&timeinfo, 0, sizeof(struct tm));
    if (strptime(str, "%Y-%m-%d %H:%M:%S", &timeinfo) != NULL)
        result = mktime(&timeinfo);
    else
        result = (time_t)-1;
    return result;
}
