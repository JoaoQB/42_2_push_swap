/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:48:50 by jqueijo-          #+#    #+#             */
/*   Updated: 2024/11/11 11:56:00 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	big_sort(t_nodestack **a, t_nodestack **b)
{
	t_nodestack	*lowest;

	while (stack_size(*a) > 3)
		pb(a, b);
	small_sort(a);
	reset_stacks(*a, *b);
	while (*b != NULL)
	{
		reset_stacks(*a, *b);
		move_nodes(a, b);
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
