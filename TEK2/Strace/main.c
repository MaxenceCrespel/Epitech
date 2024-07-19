/*
** EPITECH PROJECT, 2023
** strace2
** File description:
** main
*/

#include "strace.h"

int handle_program_exit(int wait_status, int option)
{
    if (WIFEXITED(wait_status)) {
        fprintf(stderr, option ? "exit_group(%d) = ?\n" :
        "exit_group(0x%x) = ?\n", WEXITSTATUS(wait_status));
        fprintf(stderr, "+++ exited with %d +++\n", WEXITSTATUS(wait_status));
    }
    return 0;
}

void single_step_and_handle_syscall(pid_t pid, int *wait_status, int option)
{
    struct user_regs_struct r;
    unsigned long instr_code;

    if (ptrace(PTRACE_GETREGS, pid, NULL, &r))
        perror("ptrace");
    instr_code = ptrace(PTRACE_PEEKTEXT, pid, r.rip, NULL);;
    if (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1)
        perror("ptrace");
    waitpid(pid, wait_status, 0);
    if ((WSTOPSIG(*wait_status) == SIGTRAP
    || WSTOPSIG(*wait_status) == SIGSTOP)
    && WIFSTOPPED(*wait_status) && is_syscall(instr_code)) {
        if (ptrace(PTRACE_GETREGS, pid, NULL, &r))
            perror("ptrace");
        print_syscall(pid, r.orig_rax, r.rax, option);
    }
}

int run_program(pid_t pid, int option)
{
    int wait_status;

    waitpid(pid, &wait_status, 0);
    while ((WSTOPSIG(wait_status) == SIGTRAP
    || WSTOPSIG(wait_status) == SIGSTOP)
    && WIFSTOPPED(wait_status))
        single_step_and_handle_syscall(pid, &wait_status, option);
    handle_program_exit(wait_status, option);
    return 0;
}

int main(int argc, const char **argv)
{
    pid_t pid;
    int option = 0;

    if (argc < 2)
        return 84;
    parse_arguments(argc, argv, &option, &pid);
    if (pid > 0)
        if (ptrace(PTRACE_ATTACH, pid, NULL, NULL) == -1) {
            perror("");
            return 1;
        }
    if (run_program(pid, option) != 0)
        return 1;
    return 0;
}
