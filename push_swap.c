/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:14:52 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/11/23 12:49:48 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_nodestack	*a;
	t_nodestack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	argv++;
	if (argc == 2)
		a = single_argv(argv);
	else if (argc > 2)
		a = create_stack(argv);
	if (a)
	{
		if (stack_size(a) <= 3)
			small_sort(&a);
		else
			big_sort(&a, &b);
	}
	print_stack(a);
	print_stack_target(b);
	pb(&b, &a);
	pb(&b, &a);
	reset_stacks(a, b);
	print_stack(a);
	print_stack_target(b);
	free_stack(a);
	free_stack(b);
	return (0);
}
