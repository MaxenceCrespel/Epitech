##
## EPITECH PROJECT, 2021
## Untitled (Workspace)
## File description:
## Makefile
##

SRC	=	./src/main.c	\
		./src/builtin.c	\
		./src/cd_builtin.c	\
		./src/env_builtin.c	\
		./src/exit_builtin.c	\
		./src/setenv_builtin.c	\
		./src/unsetenv_builtin.c	\
		./src/executions.c	\
		./src/minishell.c		\
		./src/semicolons.c	\
		./src/exec_commands.c	\
		./src/pipe.c	\
		./src/setenv.c	\
		./src/clean_str.c	\
		./src/get_path.c

OBJ		=	$(SRC:.c=.o)

NAME	=	mysh

NCURSES = -lncurses

FLAG = -Wall -Wextra

CSFML =  -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -Wall -Wextra -o $(NAME) $(OBJ) -I include -L. lib/my/libmy.a -g

clean:
	rm -f $(OBJ)
	make clean -C lib/my

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my

re:	fclean all
