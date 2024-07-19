##
## EPITECH PROJECT, 2021
## makefile
## File description:
## Makefile
##

#MAKEFLAGS += --silent

SRC  =  main.cpp \
		condition_variable.cpp \
		mutex.cpp \
		thread.cpp \
		reception.cpp \
		utils.cpp \
		pizzas.cpp \
		kitchen.cpp \
		reception_backprocess.cpp \
		reception_data.cpp \
		cook.cpp \
		kitchen_status.cpp \
		log_file.cpp


OBJ  =  $(SRC:.cpp=.o)

NAME =  plazza

CFLAGS_VALGRIND  =  -g3 -std=c++20 -W -Wall -Wextra \
					-Wno-ignored-qualifiers -pthread

CFLAGS	=	-pthread

all	:	$(NAME)

$(NAME):    $(OBJ)
	g++ -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:    clean
	rm -f $(NAME)

re:    fclean all

valgrind:
	g++ -o $(NAME) $(SRC) $(CFLAGS_VALGRIND)

re_valgrind:	fclean valgrind
