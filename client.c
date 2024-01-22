/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:13:47 by mmezyan           #+#    #+#             */
/*   Updated: 2024/01/22 15:28:21 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_convert_send_bites(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		usleep(80);
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
	}
}

void	ft_client(int pid, char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		ft_convert_send_bites(string[i], pid);
		i++;
	}
}

int	main(int arc, char **arv)
{
	int	pid;

	if (arc != 3)
		return (-1);
	pid = ft_atoi(arv[1]);
	if (pid == -1 || pid == 0)
		return (-1);
	ft_client(pid, arv[2]);
	return (0);
}
