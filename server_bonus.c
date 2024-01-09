#include "minitalk.h"
int i;

void ft_putchar (int c)
{
	write (1, &c, 1);
}

int reverse_bits( int b)
{
	int	r = 0;
	int	byte_len = 8;

	while (byte_len--)
	{
		r = (r << 1) | (b & 1);
		b >>= 1;
	}
	return (r);
}

void	handler_siguser1(int sig, siginfo_t *info,void *zaida)
{
	static int c;
	int pid;

	zaida = NULL;
	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c = (c << 1) | 0;
	i++;
	if(i == 8)
	{
		if (!pid)
			pid = info->si_pid;
		int tmp;
		tmp = reverse_bits(c);
		ft_putchar((char)tmp);
		kill(pid,SIGUSR1);
		i = 0;
		c = 0;
	}	
}

int	main(void)
{
	int pid;
	struct sigaction ss;

	pid = getpid();
	printf("%d\n",pid);
	ss.sa_sigaction = &handler_siguser1;
	ss.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1,&ss,NULL);
	sigaction(SIGUSR1,&ss,NULL);
	while (1){
		pause();	
	}
	return (0);
}

