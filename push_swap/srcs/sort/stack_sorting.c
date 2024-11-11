/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:53:09 by jqueijo-          #+#    #+#             */
/*   Updated: 2024/11/11 11:56:06 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_nodestack	*get_cheapest(t_nodestack *stack)
{
	t_nodestack	*cheapest;

	cheapest = stack;
	while (stack)
	{
		if (stack->push_price < cheapest->push_price)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}

void	set_push_cost(t_nodestack *b)
{
	while (b)
	{
		b->push_price = get_push_cost(b);
		b = b->next;
	}
}

void	rotate_both(t_nodestack **a, t_nodestack **b, t_nodestack *cheap)
{
	while (*a != cheap->target && *b != cheap)
	{
		if (cheap->position == 1 && cheap->target->position == 1)
			rr(a, b);
		else if (cheap->position == 2 && cheap->target->position == 2)
			rrr(a, b);
	}
}

void	rotate_to_top(t_nodestack **a, t_nodestack **b, t_nodestack *cheapest)
{
	while (*a != cheapest->target)
	{
		if (cheapest->target->position == 1)
			ra(a);
		else if (cheapest->target->position == 2)
			rra(a);
	}
	while (*b != cheapest)
	{
		if (cheapest->position == 1)
			rb(b);
		else if (cheapest->position == 2)
			rrb(b);
	}
}

void	move_nodes(t_nodestack **a, t_nodestack **b)
{
	t_nodestack	*cheapest;

	if (!*a || !*b)
		return ;
	cheapest = get_cheapest(*b);
	if ((cheapest->position == 1 && cheapest->target->position == 1)
		|| (cheapest->position == 2 && cheapest->target->position == 2))
		rotate_both(a, b, cheapest);
	rotate_to_top(a, b, cheapest);
	pa(b, a);
}
