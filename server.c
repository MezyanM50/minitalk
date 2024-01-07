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

void	handler_siguser1(int sig)
{
	static int c;
	
	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c = (c << 1) | 0;
	i++;
	if(i == 8)
	{
		int tmp;
		tmp = reverse_bits(c);
		ft_putchar((char)tmp);
		i = 0;
		c = 0;
	}	
}

int	main(void)
{
	int pid;

	pid = getpid();
	printf("%d\n",pid);
	signal(SIGUSR1, handler_siguser1);
	signal(SIGUSR2, handler_siguser1);
	while (1){
	
		//sleep(1);
	}
	return (0);
}

