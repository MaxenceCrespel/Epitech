##
## EPITECH PROJECT, 2023
## strace2
## File description:
## Makefile
##


CC	= gcc

RM	= rm -f


NAME	= strace

SRCS	= get_str_arg.c		\
		  main.c		\
		  parse_arguments.c	\
          print_arg.c		\
		  print_syscall_args.c	\
          trace.c		\
		  usefull_functions.c \

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
