/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:13:42 by jqueijo-          #+#    #+#             */
/*   Updated: 2024/11/11 11:56:15 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	set_position(t_nodestack *stack)
{
	int	lenght;

	if (!stack)
		return ;
	lenght = stack_size(stack);
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

	if (!stack)
		return ;
	lenght = stack_size(stack);
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

void	set_target(t_nodestack *a, t_nodestack *b)
{
	t_nodestack	*current;
	t_nodestack	*target;

	while (b)
	{
		current = a;
		target = NULL;
		if (b->value > get_highest(a)->value)
			target = get_lowest(a);
		else
		{
			while (current)
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
		b = b->next;
	}
}

void	reset_stacks(t_nodestack *a, t_nodestack *b)
{
	set_all(a);
	set_all(b);
	set_target(a, b);
	set_push_cost(b);
}
