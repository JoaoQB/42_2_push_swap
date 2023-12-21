/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:10:19 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/12/21 11:35:01 by jqueijo-         ###   ########.fr       */
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
	ssize_t	written;

	swap(a);
	written = write(1, "sa\n", 3);
	(void)written;
}

void	sb(t_nodestack *b)
{
	ssize_t	written;

	swap(b);
	written = write(1, "sb\n", 3);
	(void)written;
}

void	ss(t_nodestack *a, t_nodestack *b)
{
	ssize_t	written;

	swap(a);
	swap(b);
	written = write(1, "ss\n", 3);
	(void)written;
}
