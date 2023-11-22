/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:48:50 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/11/22 21:08:01 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_nodestack **a, t_nodestack **b)
{
	while (stack_size(*a) > 3)
		pb(a, b);
	small_sort(a);
	set_target(*a, *b);
	set_all(*a);
	set_all(*b);
}
