/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:13:58 by mmezyan           #+#    #+#             */
/*   Updated: 2024/01/10 12:22:23 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_i;

void	ft_putchar(int c)
{
	write (1, &c, 1);
}

int	reverse_bits( int b)
{
	int	r;
	int	byte_len;

	r = 0;
	byte_len = 8;
	while (byte_len--)
	{
		r = (r << 1) | (b & 1);
		b >>= 1;
	}
	return (r);
}

void	handler_siguser1(int sig)
{
	static int	c;
	int			tmp;

	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c = (c << 1) | 0;
	g_i++;
	if (g_i == 8)
	{
		tmp = reverse_bits(c);
		ft_putchar((char)tmp);
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
	{
		pause();
	}
	return (0);
}
