/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:25:10 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/11/10 14:39:57 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodestack	*get_highest(t_nodestack *stack)
{
	t_nodestack	*highest;

	highest = stack;
	while (stack->next != NULL)
	{
		if (stack->next->value > highest->value)
			highest = stack->next;
		stack = stack->next;
	}
	return (highest);
}

t_nodestack	*get_lowest(t_nodestack *stack)
{
	t_nodestack	*lowest;

	lowest = stack;
	while (stack->next != NULL)
	{
		if (stack->next->value < lowest->value)
			lowest = stack->next;
		stack = stack->next;
	}
	return (lowest);
}