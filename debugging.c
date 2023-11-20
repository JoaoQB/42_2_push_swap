/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:07:54 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/11/20 13:42:20 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Print stack functions, useful but cannot be included in the project due to the use of printf*/

void	print_stack(t_nodestack *lst)
{
    t_nodestack *tmp;
    int size = 0;

    if (!lst)
    {
        printf("List is empty\n");
        return;
    }

    printf("+-------+----------+\n");
    printf("| Value | Index    |\n");
    printf("+-------+----------+\n");

    tmp = lst;

    while (tmp)
    {
        printf("| %-5d | %-8d |\n", tmp->value, tmp->index);
        tmp = tmp->next;
        size += 1;
    }

    printf("+-------+----------+\n");
    printf("Stack index: %d\nStack size: %d\n", lst->index, size);
}

void	print_stack_target(t_nodestack *lst)
{
	t_nodestack	*tmp;
	int	size;

	if (!lst)
	{
		printf("List is empty\n");
		return;
	}
	printf("+-------+----------+--------+\n");
	printf("| Value | Index    | Target |\n");
	printf("+-------+----------+--------+\n");
	tmp = lst;
	size = 0;
	while (tmp)
	{
		printf("| %-5d | %-8d | %-6d |\n",
		tmp->value, tmp->index, tmp->target->value);
		tmp = tmp->next;
		size += 1;
	}
	printf("+-------+----------+-------+--------+--------+\n");
	printf("Stack index: %d\nStack size: %d\n", lst->index, size);
}

