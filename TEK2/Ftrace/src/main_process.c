/*
** EPITECH PROJECT, 2023
** main_process.c
** File description:
** Main process.
*/

#include "ftrace.h"
#include "syscall_mod.h"


int display_syscall(struct user_regs_struct regs)
{
    long syscall_idx = regs.orig_rax;
    size_t regis[6] = {regs.rdi, regs.rsi, regs.rdx,
                        regs.rcx, regs.r8, regs.r9};

    if (!(syscall_idx >= 0 && syscall_idx <= 328))
        return (84);
    printf("Syscall %s (", table[syscall_idx].name);
    for (int i = 0; i < table[syscall_idx].nargs; i++) {
        printf("0x%lx", regis[i]);
        if (i != table[regs.orig_rax].nargs - 1)
            printf(", ");
    }
    printf(") = ");
    if (syscall_idx == 162 || syscall_idx == 231) {
        printf("?\n");
        return (0);
    }
    printf("0x%llx\n", regs.rax);
    return (0);
}

int handling_symbol(ftrace_t *ft, struct user_regs_struct regs)
{
    unsigned mem = 0;
    mem = ptrace(PTRACE_PEEKTEXT, ft->pid, regs.rip, NULL);
    if (((unsigned) 0xFF & mem) == 0xE8)
        return (print_symbol(ft));
    if (((unsigned) 0xFF & mem) == 0xC3)
        return (print_ret(ft));
    return (display_syscall(regs));
}

void print_main_entering(ftrace_t *ft)
{
    for (size_t i = 0; i < ft->length; i++) {
        if (!strcmp(ft->info[i].name, "main"))
            printf("Entering function %s at 0x%ld\n",
            ft->info[i].name, ft->info[i].st_value64);
    }
}

int main_process(ftrace_t *ft)
{
    int status = 0;
    struct user_regs_struct regs;
    print_main_entering(ft);
    wait(&status);
    if (ptrace(PTRACE_SETOPTIONS, ft->pid, NULL, PTRACE_O_TRACEEXIT) == -1)
        return (perror_handling("ptrace"));
    while (!WIFEXITED(status)) {
        if (ptrace(PTRACE_SINGLESTEP, ft->pid, NULL, NULL) == -1)
            return (perror_handling("ptrace"));
        wait(&status);
        if (WIFEXITED(status))
            break;
        if (ptrace(PTRACE_GETREGS, ft->pid, NULL, &regs) == -1)
            return (perror_handling("ptrace"));
        handling_symbol(ft, regs);
    }
    printf("Leaving function main\n");
    return (0);
}
