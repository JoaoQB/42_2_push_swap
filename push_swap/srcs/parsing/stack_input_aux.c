/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_input_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:04:02 by jqueijo-          #+#    #+#             */
/*   Updated: 2024/11/11 11:55:48 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* Input check for odd characters*/
int	input_char_validation(char **argv)
{
	int	j;
	int	i;

	j = 0;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] == '+' || argv[j][i] == '-')
				i++;
			if (argv[j][i] < '0' || argv[j][i] > '9')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

/* Check stack to see if it's already sorted*/
int	check_sorted(t_nodestack *stack)
{
	t_nodestack	*temp;

	temp = stack;
	if (!temp)
		exit(1);
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

/* Check stack for duplicates.*/
int	check_duplicate(t_nodestack *stack)
{
	t_nodestack	*temp_i;
	t_nodestack	*temp_j;

	temp_i = stack;
	while (temp_i != NULL)
	{
		temp_j = temp_i->next;
		while (temp_j != NULL)
		{
			if (temp_i->value == temp_j-> value)
				return (1);
			temp_j = temp_j->next;
		}
		temp_i = temp_i->next;
	}
	return (0);
}

/* Check stack*/
// void	check_stack(t_nodestack *stack, char **argv, int argc)
// {
// 	if (check_duplicate(stack))
// 		ft_error("Error\n", stack, argv, argc);
// 	else if (check_sorted(stack))
// 	{
// 		free_stack(stack);
// 		if (argc == 2)
// 			ft_free_argv(argv);
// 		exit(1);
// 	}
// }

void	check_stack(t_nodestack *stack, char **argv, int argc)
{
	if (check_duplicate(stack))
		ft_error("Error\n", stack, argv, argc);
	else if (check_sorted(stack))
		ft_error("", stack, argv, argc);
}

t_nodestack	*get_last_node(t_nodestack *stack)
{
	t_nodestack	*last;

	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	last = stack;
	return (last);
}
