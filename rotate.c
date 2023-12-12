/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:39:16 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/12/12 18:28:20 by jqueijo-         ###   ########.fr       */
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

// void	ra(t_nodestack **stack)
// {
// 	rotate(stack);
// 	write(1, "ra\n", 3);
// 	set_all(*stack);
// }

// void	rb(t_nodestack **stack)
// {
// 	rotate(stack);
// 	write(1, "rb\n", 3);
// 	set_all(*stack);
// }

// void	rr(t_nodestack	**a, t_nodestack **b)
// {
// 	rotate(a);
// 	rotate(b);
// 	write(1, "rr\n", 3);
// 	set_all(*a);
// 	set_all(*b);
// }

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
