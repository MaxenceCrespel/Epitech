/*
** EPITECH PROJECT, 2021
** myh
** File description:
** printfh
*/

#ifndef PRINT_H
    #define PRINT_H

    #include <unistd.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <stdlib.h>

void my_putchar(char c);
void my_printf(char *str, ...);
void which_modulo2(char *str, va_list arg, int i);
void which_modulo(char *str, va_list arg, int i);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int convert_octal(int nb);
int my_put_unsigned(unsigned int nb);
int convert_bin(int nb);
int convert_hex_x(int nb);
int convert_hex_maj(int nb);
void my_printf(char *str, ...);
char *my_strdup(char *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
char *my_itoa(int nb);
int my_atoi(char *str);
char **my_str_to_word_array(char *str, char *lim);
char *my_strlow(char *str);
void printf_double_tab(char **arg);
char *my_malloc(int len);
int my_str_isnum(char *str);
char *my_strcpy(char *dest, char *src);
int my_strncmp(char *s1, char *s2);

#endif
