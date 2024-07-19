/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <uuid/uuid.h>
    #include <time.h>
    #include <ctype.h>
    #define MAX_MSG_LEN 1024

    typedef struct info_s {
        char *username;
        char *uuid;
    } info_t;

// commands_bis.c
char *get_uuid_from_username(char *username);
void split_lines(char *input_str);
void messages_command(char **tokens, char *message);

// commands.c
void login_command(char *str, char *uuid_str, info_t *info_client);
void logout_command(char *str, char *uuid_str, info_t *info_client);
void user_command(char **tokens);
void users_command(char **tokens);
void send_command(char **tokens, char *message);

// handle_response_bis.c
void handle_server_response_bis_bis_bis_bis_bis_bis_bis(char **tokens,
info_t *info_client);
void handle_server_response_bis_bis_bis_bis_bis_bis(char **tokens,
info_t *info_client);
void handle_server_response_bis_bis_bis_bis_bis(char **tokens,
info_t *info_client);
void handle_server_response_bis_bis_bis_bis(char **tokens,
info_t *info_client);

// handle_response.c
void handle_server_response_bis_bis_bis(char **tokens,
info_t *info_client, char *message);
void handle_server_response_bis_bis(char **tokens,
info_t *info_client, char *message);
void handle_server_response_bis(char **tokens,
info_t *info_client, char *message);
void handle_server_reponse(char **tokens, info_t *info_client, char *message);

// main.c
void error_exit(void);
int client(char *server_ip, int server_port);
void usage(void);
int main(int ac, char **av);

// messages_functions.c
void setup_fd_set(int sockfd, fd_set* readfds);
void wait_for_activity(int sockfd, fd_set* readfds);
void send_input(int sockfd, char *send_message);
void receive_message_func(int sockfd, char *receive_message,
info_t *info_client);
void send_messages(int sockfd);

// parsing_functions.c
void replace_char(char *str, char char1, char char2);
char **split_string(char *input_str, const char *delimeter, int *num_tokens);
char *concatenate_tokens(char **tokens);
void clear_first_word(char *str);
time_t convert_string_to_time(char *str);

// server_connection.c
int create_socket(void);
void set_server_address(struct sockaddr_in *server_addr,
char *server_ip, int server_port);
void connect_to_server(int sockfd, struct sockaddr_in *server_addr);

#endif /* !CLIENT_H_ */
