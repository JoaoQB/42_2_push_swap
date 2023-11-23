/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:13:42 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/11/23 12:48:12 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_nodestack *stack)
{
	int	lenght;

	lenght = stack_size(stack);
	if (!stack)
		return;
	while (stack)
	{
		if (stack->index <= lenght / 2)
			stack->position = 1;
		else if (stack->index > lenght / 2)
			stack->position = 2;
		stack = stack->next;
	}
}

void	set_cost(t_nodestack *stack)
{
	int	lenght;

	lenght	= stack_size(stack);
	if (!stack)
		return;
	while (stack)
	{
		if (stack->position == 1)
			stack->cost = stack->index;
		else if (stack->position == 2)
			stack->cost = lenght - stack->index;
		stack = stack->next;
	}
}

void	set_all(t_nodestack *stack)
{
	re_index(stack);
	set_position(stack);
	set_cost(stack);
}

void	set_target_pushcost(t_nodestack *a, t_nodestack *b)
{
	t_nodestack	*current;
	t_nodestack	*target;

	while (b)
	{
		current = a;
		target = NULL;
		while (current)
		{
			if (b->value > get_highest(a)->value)
			{
				target = get_lowest(a);
				break;
			}
			else
			{
				if (current->value > b->value)
				{
					if (!target || current->value < target->value)
						target = current;
				}
				current = current->next;
			}
		}
		b->target = target;
		b->push_price = get_push_cost(b);
		b = b->next;
	}
}

void	reset_stacks(t_nodestack *a, t_nodestack *b)
{
	set_all(a);
	set_all(b);
	set_target_pushcost(a, b);
}
