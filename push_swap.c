/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:14:52 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/11/10 14:45:31 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_nodestack	*a;
	// t_nodestack	*b;

	a = NULL;
	// b = NULL;
	if (argc < 2)
		return (0);
	argv++;
	if (argc == 2)
		a = single_argv(argv);
	else if (argc > 2)
		a = create_stack(argv);
	// printf("The highest node is: %d in index %d", get_highest(a)->value, get_highest(a)->index);
	// print_stack(a);
	if (a)
	{
		if (stack_size(a) <= 3)
			small_sort(&a);
	}
	// print_stack(a);
	free_stack(a);
	// free_stack(b);
	return (0);
}
