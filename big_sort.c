/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:48:50 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/11/23 12:49:13 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_nodestack **a, t_nodestack **b)
{
	while (stack_size(*a) > 3)
		pb(a, b);
	small_sort(a);
	// while (b)
	// {
	// 	reset_stacks(*a, *b);
	// 	move_nodes(*a, *b);
	// }
	set_all(*a);
	set_all(*b);
	set_target_pushcost(*a, *b);
}
