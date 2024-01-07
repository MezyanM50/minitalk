#include "minitalk.h"

int	ft_atoi(const char *str)
{
	long	results;
	int		sign;
	int		i;

	i = 0;
	results = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		results = (results * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(results * sign));
}
