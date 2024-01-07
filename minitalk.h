#ifndef MINITALK_H
# define MINITALK_H


#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>
void	ft_server(void);
void	ft_client(int pid, char *string);
void	ft_convert_sent_bites(char c, int pid);
int	ft_atoi(const char *str);



#endif
