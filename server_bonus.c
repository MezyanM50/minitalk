/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:13:55 by mmezyan           #+#    #+#             */
/*   Updated: 2024/02/06 13:07:29 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_i;

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

// int	reverse_bits(int b)
// {
// 	int	r;
// 	int	byte_len;

// 	r = 0;
// 	byte_len = 8;
// 	while (byte_len--)
// 	{
// 		r = (r << 1) | (b & 1);
// 		b >>= 1;
// 	}
// 	return (r);
// }
void	handler_siguser1(int sig, siginfo_t *info, void *zaida)
{
	static int	c;
	int			pid;
	//int			tmp;

	pid = info->si_pid;
	(void)zaida;
	if (sig == SIGUSR1)
		c = c << 1 | 1;
	else if (sig == SIGUSR2)
		c = c << 1 | 0;
	g_i++;
	if (g_i == 8)
	{
		//tmp = reverse_bits(c);
		if (c == '\0')
		{
			if (kill(pid, SIGUSR2) == -1)
				return ;
		}
		
		if (c != '\0')
		{
			ft_putchar((char)c);
			if (kill(pid, SIGUSR1) == -1)
				return ;
		}
		g_i = 0;
		c = 0;
	}
}
// void	handler_siguser1(int sig, siginfo_t *info, void *zaida)
// {
// 	static int	c;
// 	int			pid;
// 	int			tmp;

// 	pid = info->si_pid;
// 	zaida = NULL;
// 	if (sig == SIGUSR1)
// 		c = (c << 1) | 1;
// 	else if (sig == SIGUSR2)
// 		c = (c << 1) | 0;
// 	g_i++;
// 	if (g_i == 8)
// 	{
// 		tmp = reverse_bits(c);
// 		if (c == '\0')
// 			kill(pid, SIGUSR2);
// 		ft_putchar((char)tmp);
// 		kill(pid, SIGUSR1);
// 		g_i = 0;
// 		c = 0;
// 	}
// }

int	main(void)
{
	int					pid;
	struct sigaction	ss;

	pid = getpid();
	printf("%d\n", pid);
	ss.sa_sigaction = &handler_siguser1;
	ss.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &ss, NULL);
	sigaction(SIGUSR2, &ss, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
