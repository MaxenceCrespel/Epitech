/*
** EPITECH PROJECT, 2022
** B-PSU-210-LIL-2-1-minishell2-maxence.crespel
** File description:
** get_path
*/

#include "../include/my.h"

char *get_path_bis(char **exec, char **check_path, char *path)
{
    char *new_path;
    int i = 0;

    if (exec[1] != NULL)
        new_path = my_str_dup(path);
    else
        do {
            new_path = my_str_dup(check_path[i]);
            new_path = my_strcat(new_path, "/");
            new_path = my_strcat(new_path, path);
            i++;
        } while (check_path[i] != NULL && exists(new_path) == 1);
    if (check_path[i] == NULL && exists(new_path) == 1)
        return NULL;
    return new_path;
}

char **get_path_ter(int line, char *path, char **env)
{
    char **check_path;
    char **non;

    if (line == -1 && path[0] == '/') {
        check_path = malloc(sizeof(char *) * 1);
        check_path[0] = my_str_dup(path);
        check_path[1] = NULL;
    } else if (line == -1)
        return NULL;
    else {
        non = my_str_to_word_array(env[line], '=');
        check_path = my_str_to_word_array(non[1], ':');
    }
    return check_path;
}

char *get_path(char **arguments, char **env)
{
    char *arg[] = {"USELESS", "PATH"};
    char *new_path;
    char **check_path;
    int line = check_existence(arg, env);
    char *path = my_str_dup(arguments[0]);
    char **exec = my_str_to_word_array(path, '/');

    if ((check_path = get_path_ter(line, path, env)) == NULL)
        return NULL;
    if ((new_path = get_path_bis(exec, check_path, path)) == NULL)
        return NULL;
    free(path);
    return new_path;
}
