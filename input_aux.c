/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:04:02 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/10/24 15:01:35 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Atoi apenas com um check extra de MIN/MAX_INT*/
long ft_atoi(const char	*string)
{
	long	nbr;
	int		sign;
	int		i;

	nbr = 0;
	i = 0;
	sign = 1;

	while((string[i] >= '\t' && string[i] <= '\r') || string[i] == ' ')
		i++;
	if (string[i] == '-' || string[i] == '+')
		if (string[i++] == '-')
			sign = -1;
	while (string[i] >= '0' && string[i] <= '9')
	{
		nbr = (nbr * 10) + (string[i] - '0');
		if ((nbr * sign) > INT_MAX || (nbr * sign) < INT_MIN)
			exit(1);
		i++;
	}
	return (nbr * sign);
}

/* Input check for odd characters*/
void input_validation(char **argv)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (argv[j][i] == '+' || argv[j][i] == '-')
				i++;
			if (argv[j][i] < '0' || argv[j][i] > '9')
				exit (1);
			i++;
		}
		j++;
	}
}
