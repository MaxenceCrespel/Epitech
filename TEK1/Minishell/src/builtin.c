/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** builtin
*/

#include "../include/my.h"

char *check_home(char **env)
{
    char *arg[] = {"USELESS", "HOME"};
    int line = check_existence(arg, env);
    char **new;

    if (line == -1) {
        new = malloc(sizeof(char *) * 1);
        new[0] = my_str_dup("/home/mcrespel");
        return (new[0]);
    }
    new = my_str_to_word_array(env[line], '=');
    return (new[1]);
}

char **exec_cd(char **args, char **env)
{
    if (args[1] != NULL)
        env = cd_command(args[1], env);
    else
        env = cd_command(check_home(env), env);
    return env;
}

char **exec_command(int a, char **args, char **env)
{
    switch (a) {
        case 0:
            env = exec_cd(args, env);
            break;
        case 1:
            env = unsetenv_command(env, args);
            return env;
            break;
        case 2:
            env = setenv_command(env, args);
            break;
        case 3:
            exit_command(args, env);
            break;
        case 4:
            print_env(env);
            break;
    }
    return env;
}
