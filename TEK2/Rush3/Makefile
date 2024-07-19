##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Make file duo Stumper 04.
##

SRC =	main.cpp \
		GraphicalMode.cpp \
		Informations.cpp \
		TextMode.cpp


NAME = MyGKrellm

OBJS = $(SRC:.cpp=.o)
 
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system 

LNCURSES = -lncurses

CWFLAGS = -std=c++20 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	g++ $(SRC) -o $(NAME) $(LNCURSES) $(SFMLFLAGS) $(CWFLAGS)
	rm -f $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all
