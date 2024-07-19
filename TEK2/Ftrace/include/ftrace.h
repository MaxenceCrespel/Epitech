/*
** EPITECH PROJECT, 2023
** ftrace.h
** File description:
** ftrace include.
*/

#ifndef FTRACE_H_
    #define FTRACE_H_
    #include <sys/types.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <sys/user.h>
    #include <string.h>
    #include <stdlib.h>
    #include <sys/ptrace.h>
    #include <sys/wait.h>
    #include <ctype.h>
    #include <errno.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <elf.h>
    #include <libelf.h>
    #include <sys/mman.h>
    #include <sys/ptrace.h>
    #include <signal.h>

typedef struct info_s {
    char *name;
    bool is_undef;
    char symbol_type;
    Elf64_Addr st_value64;
    Elf32_Addr st_value32;
} info_t;

typedef struct ftrace_s {
    char **env;
    pid_t pid;
    char *command;
    size_t length;
    size_t idx;
    info_t *info;
    struct user_regs_struct regs;
    char **ret;
} ftrace_t;

/* error_handling.c */
int perror_handling(char *err);

/* main.c */
int helper(void);
int main(int args, char **av, char **env);

/* retrieve_symbols.c */
int init_info_tab_64(ftrace_t *ft, Elf64_Shdr *shdr, size_t i, void *buff);
void init_struct_64(ftrace_t *ft, Elf64_Ehdr *ehdr, Elf64_Shdr *shdr, void *b);
void save_value_64(ftrace_t *ft, Elf64_Sym *sym, char *name);
int fill_struct_nm_64(ftrace_t *ft, Elf64_Shdr *shdr, size_t i, void *buff);
int initialize_list(ftrace_t *ft, char **av);

/* display_symbols.c */
void put_ret_in_tab(ftrace_t *ft, char *name);
void print_entry(ftrace_t *ft, struct user_regs_struct regs);
int print_symbol(ftrace_t *ft);
int print_ret(ftrace_t *ft);

/* main_process.c */
int display_syscall(struct user_regs_struct regs);
int handling_symbol(ftrace_t *ft, struct user_regs_struct regs);
void print_main_entering(ftrace_t *ft);
int main_process(ftrace_t *ft);

/* my_ftrace.c */
ftrace_t initialize_struct(char *command, char **env);
int fork_process(ftrace_t *ft, char **av);
int my_ftrace(char *command, char **env, char **av);
int start_ftrace(ftrace_t *ft, char **av);

/* handling_file.c */
bool is_elf64_incomplete(struct stat statbuf, char *filename);
bool is_unrecognized(char *filename);
int handling_file(char *filename, struct stat statbuf);

#endif /* !FTRACE_H_ */
