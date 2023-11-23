/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:25:10 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/11/23 17:37:31 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodestack	*get_highest(t_nodestack *stack)
{
	t_nodestack	*highest;

	highest = stack;
	while (stack->next != NULL)
	{
		if (stack->next->value > highest->value)
			highest = stack->next;
		stack = stack->next;
	}
	return (highest);
}

t_nodestack	*get_lowest(t_nodestack *stack)
{
	t_nodestack	*lowest;

	lowest = stack;
	while (stack->next != NULL)
	{
		if (stack->next->value < lowest->value)
			lowest = stack->next;
		stack = stack->next;
	}
	return (lowest);
}

void	re_index(t_nodestack *a)
{
	t_nodestack	*temp;
	int			i;

	i = 0;
	if (!a)
		return ;
	temp = a;
	while (temp != NULL)
	{
		temp->index = i++;
		temp = temp->next;
	}
}

int	stack_size(t_nodestack *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack->index + 1);
}

int	get_push_cost(t_nodestack *node)
{
	int	push_cost;

	if ((node->position == 1 && node->target->position == 1)
		|| (node->position == 2 && node->target->position == 2))
	{
		if (node->cost >= node->target->cost)
			push_cost = node->cost;
		else
			push_cost = node->target->cost;
	}
	else
		push_cost = node->cost + node->target->cost;
	return (push_cost);
}
