#include<stdio.h>
#include "minitalk.h"

void	ft_convert_send_bites(char c, int pid)
{
	int i;

	i = 0;
	while (i < 8)
	{
		usleep(50);
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
	}
}

void	ft_client(int pid, char *string)
{
	int i;

	i = 0;
	while (string[i])
	{
		ft_convert_send_bites(string[i], pid);
		i++;		
	}
}

void handle_sig1(int sig)
{
	if (sig== SIGUSR1)
		printf("wsal\n");
}

void stop_fix(int sig)
{
	if (sig == SIGUSR2)
		exit(0);
}

int main(int arc,char **arv)
{
	int pid;

	if (arc != 3)
		return -1;
	pid = ft_atoi(arv[1]);
	if (pid == -1)
		return -1;
	ft_client(pid,arv[2]);
	signal(SIGUSR1, handle_sig1);
	signal(SIGUSR2, stop_fix);
	while (1)
		;
	return (0);
}
