##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## myprintf
##

SRC	=	my_putchar.c \
		my_strlen.c \
		my_putstr.c \
		my_put_unsigned.c \
		my_printf.c \
		my_put_nbr.c \
		which_modulo.c \
		my_convert.c \
		my_strdup.c \
		my_strcmp.c \
		my_strcat.c \
		my_itoa.c \
		my_atoi.c \
		my_str_to_word_array.c \
		my_strlowcase.c \
		print_double_tab.c \
		my_malloc.c \
		my_str_isnum.c \
		my_strcpy.c \
		my_strncmp.c \

NAME = libmy.a

OBJ = $(SRC:.c=.o)

all :	$(OBJ)
		ar rc $(NAME) $(OBJ)
clean :
		rm -f $(OBJ)
fclean :	clean
			rm -f $(NAME)
			rm -f *.gcda
			rm -f *.gcno
re :	fclean all
