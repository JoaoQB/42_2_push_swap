/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:48:50 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/11/23 18:31:57 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_nodestack **a, t_nodestack **b)
{
	t_nodestack	*lowest;

	while (stack_size(*a) > 3)
		pb(a, b);
	small_sort(a);
	reset_stacks(*a, *b);
	// print_stack(*a);
	// print_stack_target(*b);
	while (*b != NULL)
	{
		reset_stacks(*a, *b);
		move_nodes(a, b);
		// print_stack(*a);
		// if (*b)
			// print_stack_target(*b);
	}
	reset_stacks(*a, *b);
	lowest = get_lowest(*a);
	while (*a != lowest)
	{
		if (lowest->position == 1)
			ra(a);
		else
			rra(a);
	}
}
