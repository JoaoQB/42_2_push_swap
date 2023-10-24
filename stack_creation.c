/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:53:18 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/10/24 15:53:23 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodestack *create_stack (char **argv)
{
	t_nodestack	*new_node;
	t_nodestack	*first_node;
	t_nodestack	*last_node;
	int			i;

	i = 0;
	while(argv[i])
	{
		if (i == 0)
		{
			first_node = create_node(i, ft_atoi(argv[i + 1]));
			last_node = first_node;
		}
		else
		{
			new_node = create_node(i, ft_atoi(argv[i + 1]));
			last_node->next = new_node;
			new_node->previous = last_node;
			last_node = new_node;
		}
		i++;
	}
	//check_stack if sorted if dups
	return (first_node);
}

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
