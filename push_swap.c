/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:14:52 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/11/10 11:16:43 by jqueijo-         ###   ########.fr       */
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





	  print_stack(a);
	// print_stack(b);
	// printf("\n");
	// pb(&a, &b);
	// printf("\n");
	// print_stack(a);
	// print_stack(b);
	// pb(&a, &b);
	// printf("\n");
	// print_stack(a);
	// print_stack(b);
	// pb(&a, &b);
	// printf("\n");
	// print_stack(a);
	// print_stack(b);
	// ss(a, b);
	// printf("\n");
	// print_stack(a);
	// print_stack(b);
	// rr(&a, &b);
	// printf("\n");
	// print_stack(a);
	// print_stack(b);
	// rrr(&a, &b);
	// printf("\n");
	// print_stack(a);
	// print_stack(b);
	free_stack(a);
	// free_stack(b);
	return (0);
}
