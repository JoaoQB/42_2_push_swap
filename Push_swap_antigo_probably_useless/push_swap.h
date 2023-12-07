/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:30:48 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/12/07 16:47:48 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // Memory allocation
# include <stddef.h> // Types and macros like NULL and size_t
# include <limits.h> // Limits
# include <stdbool.h> // boolean types and values
# include <unistd.h> // System calls, write
# include <stdio.h> // Printf

/* Stack structure*/
typedef struct s_nodestack
{
	int					value;
	int					index;
	int					position;
	int					cost;
	int					push_price;
	struct s_nodestack	*next;
	struct s_nodestack	*previous;
	struct s_nodestack	*target;
}	t_nodestack;

/* Debugging*/
void		print_stack(t_nodestack *lst);
void		print_stack_target(t_nodestack *lst);

/* Input validation and stack creation
	(stack_creation.c and stack_input_aux.c)*/
t_nodestack	*create_node(int index, int value);
t_nodestack	*create_stack(char **argv);
long		ft_atoi(const char	*string);
int			input_char_validation(char **argv);
void		check_stack(t_nodestack *stack);
int			check_duplicate(t_nodestack *stack);
int			check_sorted(t_nodestack *stack);
void		free_stack(t_nodestack *stack);

/* Error in input*/
void		ft_error(char *string);

/* String aux. functions (str_aux.c and ft_split.c)*/
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		**ft_split(char const *s, char c);
void		ft_free_argv(char **argv);
t_nodestack	*single_argv(char **argv);

/* Stack movements (push.c, reverse_rotate.c, rotate.c)*/
void		sa(t_nodestack *a);
void		sb(t_nodestack *b);
void		ss(t_nodestack *a, t_nodestack *b);
void		pa(t_nodestack **source, t_nodestack **dest);
void		pb(t_nodestack **source, t_nodestack **dest);
void		ra(t_nodestack **stack);
void		rb(t_nodestack **stack);
void		rr(t_nodestack	**a, t_nodestack **b);
void		rra(t_nodestack **stack);
void		rrb(t_nodestack **stack);
void		rrr(t_nodestack **a, t_nodestack **b);

/* Sorting functions and sorting aux. functions
	(small_sort.c, big_sort.c, stack_handling_aux.c, stack_sorting.c)*/
t_nodestack	*get_highest(t_nodestack *stack);
t_nodestack	*get_lowest(t_nodestack *stack);
t_nodestack	*get_last_node(t_nodestack *stack);
int			get_push_cost(t_nodestack *node);
int			stack_size(t_nodestack *stack);
void		re_index(t_nodestack *a);
void		small_sort(t_nodestack	**stack);
void		big_sort(t_nodestack **a, t_nodestack **b);
t_nodestack	*get_cheapest(t_nodestack *stack);
void		rotate_both(t_nodestack **a, t_nodestack **b, t_nodestack *cheap);
void		move_nodes(t_nodestack **a, t_nodestack **b);
void		set_push_cost(t_nodestack *b);

/* Stack management*/
void		set_position(t_nodestack *stack);
void		set_cost(t_nodestack *stack);
void		set_target(t_nodestack *a, t_nodestack *b);
void		set_all(t_nodestack *stack);
void		reset_stacks(t_nodestack *a, t_nodestack *b);

#endif
