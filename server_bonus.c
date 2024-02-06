/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:13:55 by mmezyan           #+#    #+#             */
/*   Updated: 2024/02/06 13:16:25 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_i;

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	handler_siguser1(int sig, siginfo_t *info, void *zaida)
{
	static int	c;

	(void)zaida;
	if (sig == SIGUSR1)
		c = c << 1 | 1;
	else if (sig == SIGUSR2)
		c = c << 1 | 0;
	g_i++;
	if (g_i == 8)
	{
		if (c == '\0')
		{
			if (kill(info->si_pid, SIGUSR2) == -1)
				return ;
		}
		if (c != '\0')
		{
			ft_putchar((char)c);
			if (kill(info->si_pid, SIGUSR1) == -1)
				return ;
		}
		g_i = 0;
		c = 0;
	}
}

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
