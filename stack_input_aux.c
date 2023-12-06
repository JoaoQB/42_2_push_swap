/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_input_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:04:02 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/12/06 19:22:53 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Input check for odd characters*/
int	input_char_validation(char **argv)
{
	int	j;
	int	i;

	j = 0;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] == '+' || argv[j][i] == '-')
				i++;
			if (argv[j][i] < '0' || argv[j][i] > '9')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

/* Check stack to see if it's already sorted*/
int	check_sorted(t_nodestack *stack)
{
	t_nodestack	*temp;

	temp = stack;
	if (!temp)
		exit(1);
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

/* Check stack for duplicates.*/
int	check_duplicate(t_nodestack *stack)
{
	t_nodestack	*temp_i;
	t_nodestack	*temp_j;

	temp_i = stack;
	while (temp_i != NULL)
	{
		temp_j = temp_i->next;
		while (temp_j != NULL)
		{
			if (temp_i->value == temp_j-> value)
				return (1);
			temp_j = temp_j->next;
		}
		temp_i = temp_i->next;
	}
	return (0);
}

/* Check stack*/
void	check_stack(t_nodestack *stack)
{
	if (check_duplicate(stack))
		ft_error("Error\n");
	else if (check_sorted(stack))
		exit(1);
}
