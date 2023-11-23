/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:53:18 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/11/23 16:08:17 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Atoi apenas com um check extra de MIN/MAX_INT*/
long	ft_atoi(const char	*string)
{
	long	nbr;
	int		sign;
	int		i;

	nbr = 0;
	i = 0;
	sign = 1;
	while ((string[i] >= '\t' && string[i] <= '\r') || string[i] == ' ')
		i++;
	if (string[i] == '-' || string[i] == '+')
		if (string[i++] == '-')
			sign = -1;
	while (string[i] >= '0' && string[i] <= '9')
	{
		nbr = (nbr * 10) + (string[i] - '0');
		if ((nbr * sign) > INT_MAX || (nbr * sign) < INT_MIN)
			ft_error("Error\n");
		i++;
	}
	return (nbr * sign);
}

t_nodestack	*create_node(int index, int value)
{
	t_nodestack	*new_node;

	new_node = (t_nodestack *)malloc(sizeof(t_nodestack));
	if (!new_node)
		return (NULL);
	new_node->index = index;
	new_node->value = value;
	new_node->next = NULL;
	new_node->previous = NULL;
	new_node->target = NULL;
	return (new_node);
}

t_nodestack	*create_stack(char **argv)
{
	t_nodestack	*new_node;
	t_nodestack	*first_node;
	t_nodestack	*last_node;
	int			i;

	i = 0;
	input_char_validation(argv);
	while (argv[i])
	{
		if (i == 0)
		{
			first_node = create_node(i, ft_atoi(argv[i]));
			last_node = first_node;
		}
		else
		{
			new_node = create_node(i, ft_atoi(argv[i]));
			last_node->next = new_node;
			new_node->previous = last_node;
			last_node = new_node;
		}
		i++;
	}
	check_stack(first_node);
	return (first_node);
}

void	free_stack(t_nodestack *stack)
{
	t_nodestack	*temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	free(stack);
}
