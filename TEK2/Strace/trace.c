/*
** EPITECH PROJECT, 2023
** strace2
** File description:
** trace
*/

#include "strace.h"
#include "syscalls_entries.h"

void print_syscall_header(unsigned long sysnum)
{
    char *buf = malloc(sizeof(char) * 25);
    t_entry *ent = NULL;

    if (sysnum <= 331) {
        ent = &g_entries[sysnum];
        if (ent->name) {
            fprintf(stderr, "%s(", ent->name);
            free(buf);
            return;
        }
    }
    snprintf(buf, sizeof(buf), "sys_%llu", sysnum);
    fprintf(stderr, "%s(", buf);
    free(buf);
}

void print_syscall_footer(unsigned long retval,
int option, unsigned long sys)
{
    fprintf(stderr, ") = ");
    if (option) {
        t_entry *ent = &g_entries[sys];
        if (ent->retval == INT)
            fprintf(stderr, "%lld\n", retval);
        else
            fprintf(stderr, "0x%llx\n", retval);
    } else {
        if (retval)
            fprintf(stderr, "0x%llx\n", retval);
        else
            fprintf(stderr, "0x0\n");
    }
}

void print_syscall(pid_t child, unsigned long sysnum,
unsigned long retval, int option)
{
    print_syscall_header(sysnum);
    print_syscall_args(child, sysnum, option);
    print_syscall_footer(retval, option, sysnum);
}

t_entry *get_syscall_entry(int num)
{
    if (num <= 331 && g_entries[num].name)
        return &g_entries[num];
    else
        return NULL;
}

