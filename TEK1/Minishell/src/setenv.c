/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** setenv
*/

#include "../include/my.h"

char **change_env_bis(char **new_env, char **args, int line)
{
    if (args[2] == NULL) {
        new_env[line] = malloc(sizeof(char) * my_strlen(args[1]));
        new_env[line] = my_str_dup(args[1]);
        new_env[line] = my_strcat(new_env[line], "=");
        new_env[line + 1] = NULL;
    } else {
        new_env[line] = malloc(sizeof(char) *
        (my_strlen(args[1]) + my_strlen(args[2])));
        new_env[line] = my_str_dup(args[1]);
        new_env[line] = my_strcat(new_env[line], "=");
        new_env[line] = my_strcat(new_env[line], args[2]);
        new_env[line + 1] = NULL;
    }
    return new_env;
}

char **change_env(char **args, char **env)
{
    int line = 0;
    char **new_env;

    for (; env[line] != NULL; line++);
    new_env = malloc(sizeof(char *) * (line + 2));
    for (line = 0; env[line] != NULL; line++)
        new_env[line] = my_str_dup(env[line]);
    new_env[line] = NULL;
    new_env = change_env_bis(new_env, args, line);
    return new_env;
}

char **modif_env(int line, char **env, char **args)
{
    char *new;
    int i = 0;
    int a = 0;

    for (; env[line][i] != '='; i++);
    new = malloc(sizeof(char) * i + 2);
    for (; a < i + 1; a++)
        new[a] = env[line][a];
    new[a] = '\0';
    new = my_strcat(new, my_strcat(args[2], "\0"));
    env[line] = my_str_dup(new);
    return env;
}
