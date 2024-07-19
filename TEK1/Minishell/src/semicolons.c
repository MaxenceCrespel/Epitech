/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** semicolons
*/

#include "../include/my.h"

char **semicolons(char *line, char **env_cpy)
{
    char **commands;
    char **argv;
    char **pipes;

    commands = my_str_to_word_array(line, ';');
    for (int i = 0; commands[i] != NULL; i++) {
        commands[i] = clean_str(commands[i]);
        pipes = my_str_to_word_array(commands[i], '|');
        if (pipes[1] != NULL)
            loop_pipe(pipes, env_cpy);
        else if (commands[i][0] != '\0' && commands[i][0] != ' '
        && commands[i][0] != '\n' && commands[i][0] != '\t') {
            argv = my_str_to_word_array(commands[i], ' ');
            env_cpy = exec_commands(argv, env_cpy);
        }
    }
    return env_cpy;
}
