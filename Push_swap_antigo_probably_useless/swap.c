/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:10:19 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/11/06 16:05:14 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_nodestack *first)
{
	int	temp_value;

	if (!first || !first->next)
		return ;
	temp_value = first->value;
	first->value = first->next->value;
	first->next->value = temp_value;
}

void	sa(t_nodestack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_nodestack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_nodestack *a, t_nodestack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
