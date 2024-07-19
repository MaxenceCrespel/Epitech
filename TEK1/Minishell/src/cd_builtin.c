/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** cd_builtin
*/

#include "../include/my.h"

void free_double(char **double_str)
{
    int end = 0;

    for (; double_str[end] != NULL; end++);
    for (; end > 0; end--)
        free(double_str[end]);
    free(double_str);
}

void print_cd_error(char *path)
{
    write(2, path, my_strlen(path));
    write(2, ": ", 3);
    write(2, strerror(errno), my_strlen(strerror(errno)));
    write(2, ".\n", 2);
}

char *cd_path(char **env, int line)
{
    int start;
    int end;
    char *path;
    int i = 0;

    for (; env[line][i] != '='; i++);
    start = i + 1;
    for (; env[line][i] != '\0'; i++);
    end = i;
    path = strcut(env[line], start, end);
    return path;
}

char **cd_minus(char **args, char **env)
{
    char *path;
    int line;
    char buff[236];

    if ((line = check_existence(args, env)) == -1)
        write(2, ": No such file or drectory.\n", 29);
    else {
        path = cd_path(env, line);
        if (chdir(path) == -1)
            print_cd_error(path);
        else {
            env = setenv_command(env, args);
            args = malloc(sizeof(char *) * 4);
            args[1] = "PWD";
            args[2] = my_str_dup(getcwd(buff, sizeof(buff)));
            args[3] = NULL;
            env = setenv_command(env, args);
        }
    }
    return env;
}

char **cd_command(char *path, char **env)
{
    char **args = malloc(sizeof(char *) * 4);
    char buff[236];

    args[1] = "OLDPWD";
    args[2] = my_str_dup(getcwd(buff, sizeof(buff)));
    args[3] = NULL;
    if (my_strlen(path) == 1 && path[0] == '-')
        cd_minus(args, env);
    else if (chdir(path) == -1)
        print_cd_error(path);
    else {
        env = setenv_command(env, args);
        args = malloc(sizeof(char *) * 4);
        args[1] = "PWD";
        args[2] = my_str_dup(getcwd(buff, sizeof(buff)));
        args[3] = NULL;
        env = setenv_command(env, args);
    }
    return env;
}
