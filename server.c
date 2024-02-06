/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:13:58 by mmezyan           #+#    #+#             */
/*   Updated: 2024/02/06 13:17:52 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_i;

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	handler_siguser1(int sig)
{
	static int	c;

	if (sig == SIGUSR1)
		c = c << 1 | 1;
	else if (sig == SIGUSR2)
		c = c << 1;
	g_i++;
	if (g_i == 8)
	{
		ft_putchar((char)c);
		g_i = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	printf("%d\n", pid);
	signal(SIGUSR1, handler_siguser1);
	signal(SIGUSR2, handler_siguser1);
	while (1)
		pause();
	return (0);
}
