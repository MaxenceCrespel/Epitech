/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** exec_commands
*/

#include "../include/my.h"

char **exec_commands(char **argv, char **env_cpy)
{
    char *builtin[] = {"cd", "unsetenv", "setenv", "exit", "env"};
    int exec = 0;

    for (int a = 0; a < 5; a++)
        if (my_strcmp(argv[0], builtin[a]) == 1) {
            exec = 1;
            env_cpy = exec_command(a, argv, env_cpy);
        }
    if (exec == 0)
        execute(argv, env_cpy);
    return env_cpy;
}
