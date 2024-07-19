##
## EPITECH PROJECT, 2023
## B-NWP-400-LIL-4-1-myteams-francois.legry
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ		=	$(SRC:.c=.o)

NAME	=	../../myteams_cli

NCURSES = -lncurses

FLAG = -Wall -Wextra

CSFML =  -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(FLAG) -o $(NAME) $(OBJ) -g -L../../libs/myteams -lmyteams -luuid

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
