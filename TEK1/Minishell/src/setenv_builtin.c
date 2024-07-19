/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** setenv_builtin
*/

#include "../include/my.h"

int setenv_error(char **args)
{
    if (args[1] == NULL || my_char_is_alpha(args[1][0]) == 0) {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        return 84;
    } else if (my_str_isalpha(args[1]) == 0 && my_str_isnum(args[1]) == 1) {
        write(2, "setenv: Variable name must "
        "contain alphanumeric characters.\n", 60);
        return 84;
    }
    return 0;
}

char **setenv_exec(char **args, int line, char **env)
{
    if ((line = check_existence(args, env)) == -1)
        env = change_env(args, env);
    else
        modif_env(line, env, args);
    return env;
}

char **setenv_command(char **env, char **args)
{
    int line = 0;

    if (args[1] == NULL)
        print_env(env);
    else if (args[2] != NULL && args[3] != NULL) {
        write(2, args[0], my_strlen(args[0]));
        write(2, ": Too many arguments.\n", 22);
        return env;
    }
    if (setenv_error(args) != 84)
        env = setenv_exec(args, line, env);
    return env;
}
