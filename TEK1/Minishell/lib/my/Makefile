##
## EPITECH PROJECT, 2021
## Untitled (Workspace)
## File description:
## Makefile
##

SRC	= 	*.c

OBJ	= 	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):
	gcc -c $(SRC) -I ../../include
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f libmy.a

fclean: clean
	rm -f $(NAME)

re:	fclean all
