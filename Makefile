CFLAGS = -Wall -Wextra -Werror
CLIENT = client.c ft_atoi.c
SERVER = server.c
CLIENT_b = client_bonus.c ft_atoi.c
SERVER_b = server_bonus.c
NAME_C = client
NAME_S = server

all: $(NAME_C) $(NAME_S)

$(NAME_C): $(CLIENT)
	cc $(CFLAGS) $^ -o $@

$(NAME_S): $(SERVER)
	cc $(CFLAGS) $< -o $@


bonus :
	cc $(CFLAGS) client_bonus.c ft_atoi.c -o client
	cc $(CFLAGS) server_bonus.c -o server

clean:
	rm -f client server

fclean: clean
	rm -f client server
 
re: fclean all