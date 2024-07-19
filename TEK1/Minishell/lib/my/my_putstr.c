/*
** EPITECH PROJECT, 2021
** maxence.crespel@epitech.eu
** File description:
** my_putstr
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        *str++;
    }
    return (0);
}
