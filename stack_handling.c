/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:13:42 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/11/20 14:51:34 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_index(t_nodestack **a)
{
	t_nodestack	*temp;
	int			i;

	i = 0;
	if (!*a)
		return ;
	temp = *a;
	while (temp != NULL)
	{
		temp->index = i++;
		temp = temp->next;
	}
}

void	set_target(t_nodestack *a, t_nodestack *b)
{
	t_nodestack	*current;
	t_nodestack	*target;

	while (b)
	{
		current = a;
		target = NULL;
		while (current)
		{
			if (b->value > get_highest(a)->value)
			{
				target = get_lowest(a);
				break;
			}
			else
			{
				if (current->value > b->value)
				{
					if (!target || current->value < target->value)
						target = current;
				}
				current = current->next;
			}
		}
		b->target = target;
		b = b->next;
	}
}
