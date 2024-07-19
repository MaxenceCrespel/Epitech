/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** pipe
*/

#include "../include/my.h"

char *clean_pipes(char **pipes, int a)
{
    pipes[a] = clean_str(pipes[a]);
    if (pipes[a][0] == '\0' || pipes[a][0] == ' '
    || pipes[a][0] == '\n' || pipes[a][0] == '\t') {
        write(2, "Invalid null command.\n", 22);
        return NULL;
    }
    return pipes[a];
}

void child_pipe(int fd_in, char *pipe_a, char **arguments, char **env, int p[2])
{
    char *path;

    if ((path = get_path(arguments, env)) == NULL)
        exit(0);
    dup2(fd_in, 0);
    if (pipe_a != NULL)
        dup2(p[1], 1);
    close(p[0]);
    execve(path, arguments, env);
    exit(EXIT_FAILURE);
}

void loop_pipe(char **pipes, char **env)
{
    int p[2];
    pid_t pid;
    int fd_in = 0;
    char **arguments;

    for (int a = 0; pipes[a] != NULL; a++) {
        if ((pipes[a] = clean_pipes(pipes, a)) == NULL)
            return;
        arguments = my_str_to_word_array(pipes[a], ' ');
        pipe(p);
        if ((pid = fork()) == -1)
            exit(EXIT_FAILURE);
        else if (pid == 0)
            child_pipe(fd_in, pipes[a + 1], arguments, env, p);
        else {
            close(p[1]);
            fd_in = p[0];
        }
    }
    waitpid(pid, NULL, 0);
}
