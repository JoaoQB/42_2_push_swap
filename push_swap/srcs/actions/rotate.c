/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:39:16 by jqueijo-          #+#    #+#             */
/*   Updated: 2024/11/11 11:55:35 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
	ssize_t	written;

	rotate(stack);
	written = write(1, "ra\n", 3);
	(void)written;
	set_all(*stack);
}

void	rb(t_nodestack **stack)
{
	ssize_t	written;

	rotate(stack);
	written = write(1, "rb\n", 3);
	(void)written;
	set_all(*stack);
}

void	rr(t_nodestack	**a, t_nodestack **b)
{
	ssize_t	written;

	rotate(a);
	rotate(b);
	written = write(1, "rr\n", 3);
	(void)written;
	set_all(*a);
	set_all(*b);
}
