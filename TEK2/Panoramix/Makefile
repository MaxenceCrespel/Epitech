##
## EPITECH PROJECT, 2023
## B-NWP-400-LIL-4-1-myteams-francois.legry
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/druid.c	\
		src/villagers.c

OBJ		=	$(SRC:.c=.o)

NAME	=	panoramix

NCURSES = -lncurses

FLAG = -Wall -Wextra

CSFML =  -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

THREAD = -pthread -lrt

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(FLAG) -o $(NAME) $(OBJ) -g $(THREAD)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
