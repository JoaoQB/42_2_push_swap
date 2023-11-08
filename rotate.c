/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:39:16 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/11/08 11:07:59 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_nodestack **stack)
{
	t_nodestack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
	last->next->previous = last;
}

void	ra(t_nodestack **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
	re_index(stack);
}

void	rb(t_nodestack **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
	re_index(stack);
}

void	rr(t_nodestack	**a, t_nodestack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	re_index(a);
	re_index(b);
}
