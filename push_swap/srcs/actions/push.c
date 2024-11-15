/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:19:11 by jqueijo-          #+#    #+#             */
/*   Updated: 2024/11/11 11:55:15 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push(t_nodestack **source, t_nodestack **dest)
{
	t_nodestack	*new_node;

	if (!*source)
		return ;
	new_node = *source;
	*source = (*source)->next;
	if (!*dest)
	{
		*dest = new_node;
		(*dest)->next = NULL;
	}
	else
	{
		(*dest)->previous = new_node;
		new_node->next = *dest;
		*(dest) = new_node;
	}
	if (*source)
		(*source)->previous = NULL;
}

void	pa(t_nodestack **source, t_nodestack **dest)
{
	ssize_t	written;

	push(source, dest);
	written = write(1, "pa\n", 3);
	(void)written;
	set_all(*source);
	set_all(*dest);
}

void	pb(t_nodestack **source, t_nodestack **dest)
{
	ssize_t	written;

	push(source, dest);
	written = write(1, "pb\n", 3);
	(void)written;
	set_all(*source);
	set_all(*dest);
}
