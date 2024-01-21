/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:13:42 by mmezyan           #+#    #+#             */
/*   Updated: 2024/01/21 20:29:43 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minitalk.h"


void	ft_convert_send_bites(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		usleep(100);
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
	}
}

void	handle_sig(int sig)
{
	if (sig == SIGUSR1)
		write(1, "success\n", 8);
	if (sig == SIGUSR2)
		exit(0);
}

void	ft_client(int pid, char *string)
{
	int	i;

	i = 0;
	signal(SIGUSR2, handle_sig);
	signal(SIGUSR1, handle_sig);
	while (string[i])
	{
		ft_convert_send_bites(string[i], pid);
		i++;
	}
	if (!string[i])
		ft_convert_send_bites(string[i], pid);
}

int	main(int arc, char **arv)
{
	int	pid;

	if (arc != 3)
		return (-1);
	pid = ft_atoi(arv[1]);
	if (pid == -1)
		return (-1);
	ft_client(pid, arv[2]);
	while (1)
		;
	return (0);
}
