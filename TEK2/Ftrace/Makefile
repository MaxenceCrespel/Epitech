##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile ftrace.
##

SRC =	src/main.c \
		src/handling_file.c \
		src/error_handling.c \
		src/retrieve_symbols.c \
		src/display_symbols.c \
		src/main_process.c \
		src/my_ftrace.c \


NAME = ftrace

OBJS = $(SRC:.c=.o)

CFLAGS += -I include/
CWFLAGS = -std=gnu17 -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(SRC) -o $(NAME) $(CFLAGS) $(CWFLAGS) -lelf -g

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all
