/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** env_builtin
*/

#include "../include/my.h"

char **cp_env(char **env)
{
    char **new_env;
    int i = 0;
    int line = 0;

    for (; env[i] != NULL; i++);
    new_env = malloc(sizeof(char *) * (i + 1));
    for (; env[line] != NULL; line++)
        new_env[line] = my_str_dup(env[line]);
    new_env[line] = NULL;
    return new_env;
}

void print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        my_printf("%s\n", env[i]);
}
