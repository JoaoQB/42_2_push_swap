/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:53:18 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/10/24 15:03:49 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodestack *create_stack ()
{}

t_nodestack *create_node(int index, int value)
{
	t_nodestack	*new_node;

	new_node = (t_nodestack *)malloc(sizeof(t_nodestack));
	if (!new_node)
		return (NULL);
	new_node->index = index;
	new_node->value = value;
	new_node->next = NULL;
	new_node->previous = NULL;
}
