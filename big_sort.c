/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:48:50 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/11/20 14:39:07 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_nodestack **a, t_nodestack **b)
{
	while (stack_size(*a) > 3)
		pb(a, b);
	small_sort(a);
	set_target(*a, *b);
}
