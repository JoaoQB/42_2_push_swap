/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:53:18 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/12/12 13:08:19 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char	*string, t_nodestack *stack, char **argv, int argc)
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
			ft_error("Error\n", stack, argv, argc);
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

t_nodestack	*create_stack(char **argv, t_nodestack *stack, int argc)
{
	t_nodestack	*new;
	t_nodestack	*first;
	t_nodestack	*last;
	int			i;

	i = 0;
	if (input_char_validation(argv))
		ft_error("Error\n", stack, argv, argc);
	while (argv[i])
	{
		if (i == 0)
			first = create_node(i, ft_atoi(argv[i], stack, argv, argc));
		else
		{
			new = create_node(i, ft_atoi(argv[i], first, argv, argc));
			last = get_last_node(first);
			last->next = new;
			new->previous = last;
			last = new;
		}
		i++;
	}
	check_stack(first, argv, argc);
	return (first);
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
