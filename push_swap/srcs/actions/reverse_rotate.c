/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:10:07 by jqueijo-          #+#    #+#             */
/*   Updated: 2024/11/11 11:55:33 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
	ssize_t	written;

	reverse_rotate(stack);
	written = write(1, "rra\n", 4);
	(void)written;
	set_all(*stack);
}

void	rrb(t_nodestack **stack)
{
	ssize_t	written;

	reverse_rotate(stack);
	written = write(1, "rrb\n", 4);
	(void)written;
	set_all(*stack);
}

void	rrr(t_nodestack **a, t_nodestack **b)
{
	ssize_t	written;

	reverse_rotate(a);
	reverse_rotate(b);
	written = write(1, "rrr\n", 4);
	(void)written;
	set_all(*a);
	set_all(*b);
}
