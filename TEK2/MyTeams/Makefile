##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SERVER	=	src/server/
CLIENT	=	src/client/

all: server client

server:
	$(MAKE) -C $(SERVER)

client:
	$(MAKE) -C $(CLIENT)

clean:
	$(MAKE) -C $(SERVER) clean
	$(MAKE) -C $(CLIENT) clean

fclean: clean
	$(MAKE) -C $(SERVER) fclean
	$(MAKE) -C $(CLIENT) fclean

re: fclean all
