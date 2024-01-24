CFLAGS = -Wall -Wextra -Werror
CLIENT = client.c ft_atoi.c
SERVER = server.c
CLIENT_b = client_bonus.c ft_atoi.c
SERVER_b = server_bonus.c
NAME_C = client
NAME_S = server
NAME_BC = client_bonus
NAME_BS = server_bonus

all: $(NAME_C) $(NAME_S)

$(NAME_C): $(CLIENT)
	cc $(CFLAGS) $^ -o $@

$(NAME_S): $(SERVER)
	cc $(CFLAGS) $< -o $@

$(NAME_BC): $(CLIENT_b)
	cc $(CFLAGS) $^ -o $@

$(NAME_BS): $(SERVER_b)
	cc $(CFLAGS) $^ -o $@

bonus : $(NAME_BC) $(NAME_BS)
	
clean:
	rm -f client server
	rm -rf client_bonus server_bonus

fclean: clean
	rm -f client server
	rm -rf client_bonus server_bonus
 
re: fclean all

.PHONY: fclean re clean bonus all