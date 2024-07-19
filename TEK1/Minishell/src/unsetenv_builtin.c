/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** unsetenv_builtin
*/

#include "../include/my.h"

char **delete_env(int line, char **env)
{
    char **new_env;
    int line_bis = 0;
    int i = 0;

    for (; env[i] != NULL; i++);
    new_env = malloc(sizeof(char *) * (i + 1));
    for (int i = 0; env[i] != NULL; i++) {
        if (line_bis == line)
            line--;
        else {
            new_env[line_bis] = my_str_dup(env[i]);
            line_bis++;
        }
    }
    new_env[line_bis] = NULL;
    return new_env;
}

char **unsetenv_exec(char **env, int line, char **args, int i)
{
    char **arguments = malloc(sizeof(char *) * 2);

    arguments[0] = my_str_dup("oui");
    arguments[1] = my_str_dup(args[i]);
    if ((line = check_existence(arguments, env)) != -1)
        env = delete_env(line, env);
    return env;
}

char **unsetenv_command(char **env, char **args)
{
    int line = 0;

    if (args[1] == NULL) {
        write(2, args[0], my_strlen(args[0]));
        write(2, ": Too few arguments.\n", 21);
    } else
        for (int i = 1; args[i] != NULL; i++)
            env = unsetenv_exec(env, line, args, i);
    return env;
}
