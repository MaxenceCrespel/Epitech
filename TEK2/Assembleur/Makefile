##
## EPITECH PROJECT, 2023
## B-ASM-400-LIL-4-1-asmminilibc-maxence.crespel
## File description:
## Makefile
##

SRCS = strlen.asm \
		strchr.asm	\
		strrchr.asm	\
		memset.asm	\
		memcpy.asm	\
		strcmp.asm	\
		memmove.asm	\
		strncmp.asm	\
		strcasecmp.asm \
		strstr.asm	\
		strpbrk.asm	\
		strcspn.asm

OBJS = $(SRCS:.asm=.o)

all: $(OBJS)
	ld -shared -o libasm.so $(OBJS)

%.o: %.asm
	nasm -f elf64 -o $@ $<

re: fclean all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f libasm.so