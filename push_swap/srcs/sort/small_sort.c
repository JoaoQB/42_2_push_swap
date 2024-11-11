/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:12:45 by jqueijo-          #+#    #+#             */
/*   Updated: 2024/11/11 11:55:57 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	sort_3(t_nodestack **stack)
{
	if (*stack == get_highest(*stack))
		ra(stack);
	else if ((*stack)->next == get_highest(*stack))
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(*stack);
}

void	small_sort(t_nodestack	**stack)
{
	if (stack_size(*stack) == 2)
		sa(*stack);
	else if (stack_size(*stack) == 3)
		sort_3(stack);
}
