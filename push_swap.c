/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:14:52 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/10/25 14:50:56 by jqueijo-         ###   ########.fr       */
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
	input_char_validation(argv);
	a = create_stack(argv);
	print_stack(a);
	free(a);
	return (0);
}
