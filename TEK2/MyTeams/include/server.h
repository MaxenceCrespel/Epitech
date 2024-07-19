/*
** EPITECH PROJECT, 2023
** B-NWP-400-LIL-4-1-myteams-francois.legry
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_
    #include <string.h>
    #include <time.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <string.h>
    #include <unistd.h>
    #include <errno.h>
    #include <sys/select.h>
    #include <uuid/uuid.h>

    typedef struct {
        char *username;
        char *uuid;
    } client_info_t;

    typedef struct {
        client_info_t *clients[FD_SETSIZE];
    } client_table_t;

    typedef struct {
        int sockfd;
        fd_set *readfds;
        int *max_fd;
    } select_params_t;

// connections.c
int create_socket(int port_number);
void handle_ready_fds(int sockfd, fd_set *readfds, int *max_fd,
client_table_t *client_table);
void handle_fd(int fd, select_params_t *select_params,
client_table_t *client_table);
void accept_new_client(int sockfd, fd_set *readfds, int *max_fd,
client_table_t *client_table);
void send_to_multiple_clients(client_table_t *client_table,
char *message_to_send);

// handle_authenticated_command.c
void handle_authenticated_command_bis_bis_bis_bis_bis_bis(int fd,
client_info_t *client_info, client_table_t *client_table, char **tokens);
void handle_authenticated_command_bis_bis_bis_bis_bis(int fd,
client_info_t *client_info, client_table_t *client_table, char **tokens);
void handle_authenticated_command_bis_bis_bis_bis(int fd,
client_info_t *client_info, client_table_t *client_table, char **tokens);
void handle_authenticated_command_bis_bis_bis(int fd,
client_info_t *client_info, client_table_t *client_table, char **tokens);
void handle_authenticated_command_bis_bis(int fd, client_info_t *client_info,
client_table_t *client_table, char **tokens);

// list_commands.c
void handle_unauthenticated_command(int fd, client_info_t *client_info,
client_table_t *client_table, char **tokens);
void handle_authenticated_command_bis(int fd, client_info_t *client_info,
client_table_t *client_table, char **tokens);
void handle_authenticated_command(int fd, client_info_t *client_info,
client_table_t *client_table, char **tokens);
int handle_command(int fd, char *str, client_table_t *client_table);

// login_command.c
FILE *open_login_file(const char *filename);
int search_user(FILE *fp, const char *username, const char *user_uuid,
client_info_t *client_info);
void create_user(FILE *fp, char *username, const char *user_uuid,
client_info_t *client_info);
void replace_char(char *str, char char1, char char2);
int login_command(client_info_t *client_info, char **tokens, int fd,
client_table_t *client_table);

// logout_command.c
void update_login_file_status(client_info_t *client_info, FILE *fp);
void send_logout_message(client_info_t *client_info,
client_table_t *client_table);
void logout_command(client_info_t *client_info, int fd,
client_table_t *client_table);

// main.c
void handle_client_message(int fd, fd_set *readfds,
client_table_t *client_table);
void usage(void);
int run_server(int sockfd);
int server(int port_number);
int main(int ac, char **av);

// messages_command.c
char **get_messages(char *username1, char *username2);
char *find_username(char **tokens);
char *append_with_semicolon(char *str1, char *str2);
void send_messages(char **messages, char **tokens,
client_info_t *client_info, int fd);
void messages_command(char **tokens, client_info_t *client_info, int fd);

// parse_commands.c
void remove_spaces(char *str);
char **split_string(char *input_str, const char *delimiter, int *num_tokens);
int is_last_char_delimiter(char *str, const char *delimiter);
void add_null_token(char **tokens, int *num_tokens, int num_tokens_allocated);

// send_command.c
char *check_uuid(char **tokens);
int check_client(client_table_t *client_table,
client_info_t *client_info, char **tokens);
void write_in_file(char *username1, char *username2, char *message);
void send_command(client_info_t *client_info, int fd, char **tokens,
client_table_t *client_table);

// user_command.c
int check_user(char *line, char *message_to_send, char *uuid, int fd);
void user_command(client_info_t *client, int fd, char *uuid);

//users_command.c
void print_users(int fd);

#endif /* !SERVER_H_ */
