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

int main(int arc,char **arv)
{
	int pid;

	if (arc != 3)
		return -1;
	pid = ft_atoi(arv[1]);
	if (pid == -1)
		return -1;
	ft_client(pid,arv[2]);
	return (0);
}
