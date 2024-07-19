/*
** EPITECH PROJECT, 2022
** B-PSU-210-LIL-2-1-minishell2-maxence.crespel
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <time.h>
    #include <stdarg.h>
    #include <signal.h>
    #include <stddef.h>
    #include <string.h>
    #include <grp.h>
    #include <pwd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <fcntl.h>
    #include <ncurses.h>
    #include <dirent.h>
    #include <errno.h>

void int_to_str(char str[], int nb);
void move_left(char *res, int nb);
void move_right(char *str);
int my_compute_power_rec(int nb , int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int check_size(char const *str, int a);
int my_getnbr_bis(char const *str, int nbr, int b);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int n);
void put_nb_to_str(char *str, char *nb, char operator);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
int my_sort_int_array_bis(int *array, int sort, int a);
void my_sort_int_array(int *array , int size);
char *my_str_dup(char *str);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char const *src);
char *strcut(char *src, int start, int end);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest , char const *src , int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char my_isalpha(char c);
int str_to_int(char *str, int start, int end);
int my_put_unsigned_nbr(unsigned int nb);
int my_put_long(long int nb);
int my_put_long_long(long long int nb);
int my_put_short(short int nb);
void octal(unsigned int nbr);
void binary(unsigned int nbr);
void hexadecimal(unsigned int nbr, char maj);
int basic_flag(const char *str, va_list ap, int a);
int my_printf(const char *str, ...);
int clean(const char *str, int a);
int hashtag(const char *str, va_list ap, int a);
void flag_bis(const char *str, va_list ap, int a);
void flag(const char *str, va_list ap, int a);
int nbr_size(va_list second);
void width_trick(const char *str, va_list ap, int a);
int my_atoi(char *str);
char **my_str_to_word_array(char *str, char c);
int my_char_is_num(char car);
int my_char_is_alpha(char car);

// builtin.c

char *check_home(char **env);
char **exec_cd(char **args, char **env);
char **exec_command(int a, char **args, char **env);

// cd_builtin.c

void free_double(char **double_str);
void print_cd_error(char *path);
char *cd_path(char **env, int line);
char **cd_minus(char **args, char **env);
char **cd_command(char *path, char **env);

// env_builtin.c

char **cp_env(char **env);
void print_env(char **env);

// exec_commands.c

char **exec_commands(char **argv, char **env_cpy);

// executions.c

int exists(const char *fname);
int exec_n_builtin(char *new_path, char **arguments, char **env);
int execute(char **arguments, char **env);

// exit_builtins.c

void exit_command(char **arguments, char **env);

// get_path.c

char *get_path_bis(char **exec, char **check_path, char *path);
char **get_path_ter(int line, char *path, char **env);
char *get_path(char **arguments, char **env);

// minishell.c

void print_path(void);
char *clean_str(char *str);
char *read_line(void);
int check_existence(char **args, char **env);
void minishell(char **env_cpy);

// pipe.c

char *clean_pipes(char **pipes, int a);
void child_pipe(int fd_in, char *pipe_a,
char **arguments, char **env, int p[2]);
void loop_pipe(char **pipes, char **env);

// semicolons.c

char **semicolons(char *line, char **env_cpy);

// setenv_builtin.c

int setenv_error(char **args);
char **setenv_exec(char **args, int line, char **env);
char **setenv_command(char **env, char **args);

// setenv.c

char **change_env_bis(char **new_env, char **args, int line);
char **change_env(char **args, char **env);
char **modif_env(int line, char **env, char **args);

// unsetenv_builtin.c

char **delete_env(int line, char **env);
char **unsetenv_exec(char **env, int line, char **args, int i);
char **unsetenv_command(char **env, char **args);


#endif
