/*
** EPITECH PROJECT, 2023
** strace2
** File description:
** header
*/

#ifndef _HEADER_H_
    #define _HEADER_H_
    #include <sys/ptrace.h>
    #include <ctype.h>
    #include <sys/user.h>
    #include <sys/reg.h>
    #include <sys/wait.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <errno.h>
    #include <string.h>
    #include <stdbool.h>

enum e_arg_type {
    INT,
    PTR,
    STR
};

typedef struct s_entry {
    const char *name;
    int nb_args;
    enum e_arg_type	args_value[6];
    enum e_arg_type	retval;
} t_entry;

// get_str_arg.c
unsigned long read_memory(pid_t child, unsigned long addr);
void realloc_val(char **val_ptr, int *val_capacity_ptr, int val_len);
unsigned long read_chunk(pid_t child, unsigned long chunk_addr);
int append_chunk_to_val(char *val, int val_len, unsigned long chunk_val);
char *get_string(pid_t child, unsigned long addr);

// main.c
int handle_program_exit(int wait_status, int option);
void single_step_and_handle_syscall(pid_t pid, int *wait_status, int option);
int run_program(pid_t pid, int option);
int main(int ac, const char **av);

// parse_arguments.c
void handle_option_option(const char *arg, int *option);
void run_child_process(const char **av, int ac, int option);
void handle_pid_option(const char **av, int ac, int option, pid_t *pid);
void parse_arguments(int ac, const char **av, int *option, pid_t *pid);

// print_arg.c
void print_str_arg(pid_t child, unsigned long arg);
void print_arg(pid_t child, unsigned long arg, int option,
enum e_arg_type type);

// print_syscall_args.c
void print_syscall_arg(pid_t child, int index, int option,
enum e_arg_type type);
t_entry *get_syscall_entry(int num);
void print_syscall_args_list(pid_t child, t_entry *entry, int option);
void print_syscall_arg_null(int nb_args, pid_t child, int option);
void print_syscall_args(pid_t child, int num, int option);

// trace.c
void print_syscall_header(unsigned long sysnum);
void print_syscall_footer(unsigned long retval,
int option, unsigned long sys);
void print_syscall(pid_t child, unsigned long sysnum,
unsigned long retval, int option);

// usefull_functions.c
bool is_syscall(unsigned short instr_code);

#endif /* !_HEADER_H_ */
