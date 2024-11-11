/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:14:52 by jqueijo-          #+#    #+#             */
/*   Updated: 2024/11/11 11:51:28 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

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
		a = single_argv(argv, a, argc);
	else if (argc > 2)
		a = create_stack(argv, a, argc);
	if (a)
	{
		if (stack_size(a) <= 3)
			small_sort(&a);
		else
			big_sort(&a, &b);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}
