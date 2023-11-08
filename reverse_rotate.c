/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:10:07 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/11/08 11:54:28 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_nodestack **stack)
{
	t_nodestack	*first;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	while (first->next != NULL)
		first = first->next;
	first->previous->next = NULL;
	first->next = *stack;
	first->previous = NULL;
	(*stack)->previous = first;
	*stack = first;
}

void	rra(t_nodestack **stack)
{
	reverse_rotate(stack);
	write(1, "rra\n", 4);
	re_index(stack);
}

void	rrb(t_nodestack **stack)
{
	reverse_rotate(stack);
	write(1, "rrb\n", 4);
	re_index(stack);
}

void	rrr(t_nodestack **a, t_nodestack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	re_index(a);
	re_index(b);
}
