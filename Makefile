CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): 
	cc $(CFLAGS) client.c ft_atoi.c -o client
	cc $(CFLAGS) server.c -o server

bonus :
	cc $(CFLAGS) client_bonus.c ft_atoi.c -o client
	cc $(CFLAGS) server_bonus.c -o server

clean:
	rm -f client server

fclean: clean
	rm -f client server
 
re: fclean all