/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_page_code.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:01:37 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/12/12 13:10:37 by jqueijo-         ###   ########.fr       */
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
t_nodestack	*create_stack(char **argv, t_nodestack *stack, int argc);
long		ft_atoi(char	*string, t_nodestack *stack, char **argv, int argc);
int			input_char_validation(char **argv);
void		check_stack(t_nodestack *stack, char **argv, int argc);
int			check_duplicate(t_nodestack *stack);
int			check_sorted(t_nodestack *stack);
void		free_stack(t_nodestack *stack);

/* Error in input*/
void		cleanup_and_exit(t_nodestack *a, char **argv, int argc);
void		ft_error(char *string, t_nodestack *a, char **argv, int argc);

/* String aux. functions (str_aux.c and ft_split.c)*/
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		**ft_split(char const *s, char c);
void		ft_free_argv(char **argv);
t_nodestack	*single_argv(char **argv, t_nodestack *stack, int argc);

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

void	cleanup_and_exit(t_nodestack *a, char **argv, int argc)
{
	free_stack(a);
	if (argc == 2)
		ft_free_argv(argv);
	exit (1);
}

void	ft_error(char *string, t_nodestack *a, char **argv, int argc)
{
	write(2, string, ft_strlen(string));
	cleanup_and_exit(a, argv, argc);
}

/* Ft_split, normally one page only.*/
static int	substr_count(const char *s, int c)
{
	size_t	count;
	size_t	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*fill_substr(const char *src, size_t len)
{
	char	*dest;

	if (!src)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, len);
	return (dest);
}

static char	**ft_free(char **strs, int count)
{
	while (--count <= 0)
		free(*(strs + count));
	free(strs);
	return (NULL);
}

static int	iterate_i(const char *s, int i, char c)
{
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**split_strs;
	int		i;
	int		j;
	int		i_word;

	split_strs = (char **)malloc((substr_count(s, c) + 1) * sizeof(char *));
	if (!split_strs || !s)
		return (NULL);
	j = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			i++;
		i_word = i;
		i = iterate_i(s, i, c);
		if (i_word < i)
		{
			*(split_strs + j++) = fill_substr(&s[i_word], (i - i_word) + 1);
			if (!(*(split_strs + j - 1)))
				return (ft_free(split_strs, j));
		}
	}
	*(split_strs + j) = NULL;
	return (split_strs);
}

/* Push, normally one page only.*/
static void	push(t_nodestack **source, t_nodestack **dest)
{
	t_nodestack	*new_node;

	if (!*source)
		return ;
	new_node = *source;
	*source = (*source)->next;
	if (!*dest)
	{
		*dest = new_node;
		(*dest)->next = NULL;
	}
	else
	{
		(*dest)->previous = new_node;
		new_node->next = *dest;
		*(dest) = new_node;
	}
	if (*source)
		(*source)->previous = NULL;
}

void	pa(t_nodestack **source, t_nodestack **dest)
{
	push(source, dest);
	write(1, "pa\n", 3);
	set_all(*source);
	set_all(*dest);
}

void	pb(t_nodestack **source, t_nodestack **dest)
{
	push(source, dest);
	write(1, "pb\n", 3);
	set_all(*source);
	set_all(*dest);
}

/* Reverse_rotate, normally one page only.*/
static void	reverse_rotate(t_nodestack **stack)
{
	t_nodestack	*first;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	while (first->next != NULL)
		first = first->next;
	first->previous->next = NULL;
	first->next = *stack;
	first->previous = NULL;
	(*stack)->previous = first;
	*stack = first;
}

void	rra(t_nodestack **stack)
{
	reverse_rotate(stack);
	write(1, "rra\n", 4);
	set_all(*stack);
}

void	rrb(t_nodestack **stack)
{
	reverse_rotate(stack);
	write(1, "rrb\n", 4);
	set_all(*stack);
}

void	rrr(t_nodestack **a, t_nodestack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	set_all(*a);
	set_all(*b);
}

/* Rotate, normally one page only.*/
static void	rotate(t_nodestack **stack)
{
	t_nodestack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
	last->next->previous = last;
}

void	ra(t_nodestack **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
	set_all(*stack);
}

void	rb(t_nodestack **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
	set_all(*stack);
}

void	rr(t_nodestack	**a, t_nodestack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	set_all(*a);
	set_all(*b);
}

/* Swap, normally one page only.*/
static void	swap(t_nodestack *first)
{
	int	temp_value;

	if (!first || !first->next)
		return ;
	temp_value = first->value;
	first->value = first->next->value;
	first->next->value = temp_value;
}

void	sa(t_nodestack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_nodestack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_nodestack *a, t_nodestack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

/* Small sort, normally on one page only*/
static void	sort_3(t_nodestack **stack)
{
	if (*stack == get_highest(*stack))
		ra(stack);
	else if ((*stack)->next == get_highest(*stack))
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(*stack);
}

void	small_sort(t_nodestack	**stack)
{
	if (stack_size(*stack) == 2)
		sa(*stack);
	else if (stack_size(*stack) == 3)
		sort_3(stack);
}

/* Self-explanatory*/
void	big_sort(t_nodestack **a, t_nodestack **b)
{
	t_nodestack	*lowest;

	while (stack_size(*a) > 3)
		pb(a, b);
	small_sort(a);
	reset_stacks(*a, *b);
	while (*b != NULL)
	{
		reset_stacks(*a, *b);
		move_nodes(a, b);
	}
	reset_stacks(*a, *b);
	lowest = get_lowest(*a);
	while (*a != lowest)
	{
		if (lowest->position == 1)
			ra(a);
		else
			rra(a);
	}
}

long	ft_atoi(char	*string, t_nodestack *stack, char **argv, int argc)
{
	long	nbr;
	int		sign;
	int		i;

	nbr = 0;
	i = 0;
	sign = 1;
	while ((string[i] >= '\t' && string[i] <= '\r') || string[i] == ' ')
		i++;
	if (string[i] == '-' || string[i] == '+')
		if (string[i++] == '-')
			sign = -1;
	while (string[i] >= '0' && string[i] <= '9')
	{
		nbr = (nbr * 10) + (string[i] - '0');
		if ((nbr * sign) > INT_MAX || (nbr * sign) < INT_MIN)
			ft_error("Error\n", stack, argv, argc);
		i++;
	}
	return (nbr * sign);
}

t_nodestack	*create_node(int index, int value)
{
	t_nodestack	*new_node;

	new_node = (t_nodestack *)malloc(sizeof(t_nodestack));
	if (!new_node)
		return (NULL);
	new_node->index = index;
	new_node->value = value;
	new_node->next = NULL;
	new_node->previous = NULL;
	new_node->target = NULL;
	return (new_node);
}

t_nodestack	*create_stack(char **argv, t_nodestack *stack, int argc)
{
	t_nodestack	*new;
	t_nodestack	*first;
	t_nodestack	*last;
	int			i;

	i = 0;
	if (input_char_validation(argv))
		ft_error("Error\n", stack, argv, argc);
	while (argv[i])
	{
		if (i == 0)
			first = create_node(i, ft_atoi(argv[i], stack, argv, argc));
		else
		{
			new = create_node(i, ft_atoi(argv[i], first, argv, argc));
			last = get_last_node(first);
			last->next = new;
			new->previous = last;
			last = new;
		}
		i++;
	}
	check_stack(first, argv, argc);
	return (first);
}

void	free_stack(t_nodestack *stack)
{
	t_nodestack	*temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	free(stack);
}

t_nodestack	*get_highest(t_nodestack *stack)
{
	t_nodestack	*highest;

	highest = stack;
	while (stack->next != NULL)
	{
		if (stack->next->value > highest->value)
			highest = stack->next;
		stack = stack->next;
	}
	return (highest);
}

t_nodestack	*get_lowest(t_nodestack *stack)
{
	t_nodestack	*lowest;

	lowest = stack;
	while (stack->next != NULL)
	{
		if (stack->next->value < lowest->value)
			lowest = stack->next;
		stack = stack->next;
	}
	return (lowest);
}

void	re_index(t_nodestack *a)
{
	t_nodestack	*temp;
	int			i;

	i = 0;
	if (!a)
		return ;
	temp = a;
	while (temp != NULL)
	{
		temp->index = i++;
		temp = temp->next;
	}
}

int	stack_size(t_nodestack *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack->index + 1);
}

int	get_push_cost(t_nodestack *node)
{
	int	push_cost;

	if ((node->position == 1 && node->target->position == 1)
		|| (node->position == 2 && node->target->position == 2))
	{
		if (node->cost >= node->target->cost)
			push_cost = node->cost;
		else
			push_cost = node->target->cost;
	}
	else
		push_cost = node->cost + node->target->cost;
	return (push_cost);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*src && size && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	if (size - i != 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}

void	ft_free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

t_nodestack	*single_argv(char **argv, t_nodestack *stack, int argc)
{
	t_nodestack	*first;

	if (!argv)
		return (NULL);
	argv = ft_split(*argv, ' ');
	if (!*argv)
		exit(1);
	first = create_stack(argv, stack, argc);
	ft_free_argv(argv);
	return (first);
}

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
void	check_stack(t_nodestack *stack, char **argv, int argc)
{
	if (check_duplicate(stack))
		ft_error("Error\n", stack, argv, argc);
	else if (check_sorted(stack))
	{
		free_stack(stack);
		if (argc == 2)
			ft_free_argv(argv);
		exit(1);
	}
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

void	set_position(t_nodestack *stack)
{
	int	lenght;

	if (!stack)
		return ;
	lenght = stack_size(stack);
	while (stack)
	{
		if (stack->index <= lenght / 2)
			stack->position = 1;
		else if (stack->index > lenght / 2)
			stack->position = 2;
		stack = stack->next;
	}
}

void	set_cost(t_nodestack *stack)
{
	int	lenght;

	if (!stack)
		return ;
	lenght = stack_size(stack);
	while (stack)
	{
		if (stack->position == 1)
			stack->cost = stack->index;
		else if (stack->position == 2)
			stack->cost = lenght - stack->index;
		stack = stack->next;
	}
}

void	set_all(t_nodestack *stack)
{
	re_index(stack);
	set_position(stack);
	set_cost(stack);
}

void	set_target(t_nodestack *a, t_nodestack *b)
{
	t_nodestack	*current;
	t_nodestack	*target;

	while (b)
	{
		current = a;
		target = NULL;
		if (b->value > get_highest(a)->value)
			target = get_lowest(a);
		else
		{
			while (current)
			{
				if (current->value > b->value)
				{
					if (!target || current->value < target->value)
						target = current;
				}
				current = current->next;
			}
		}
		b->target = target;
		b = b->next;
	}
}

void	reset_stacks(t_nodestack *a, t_nodestack *b)
{
	set_all(a);
	set_all(b);
	set_target(a, b);
	set_push_cost(b);
}

t_nodestack	*get_cheapest(t_nodestack *stack)
{
	t_nodestack	*cheapest;

	cheapest = stack;
	while (stack)
	{
		if (stack->push_price < cheapest->push_price)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}

void	set_push_cost(t_nodestack *b)
{
	while (b)
	{
		b->push_price = get_push_cost(b);
		b = b->next;
	}
}

void	rotate_both(t_nodestack **a, t_nodestack **b, t_nodestack *cheap)
{
	while (*a != cheap->target && *b != cheap)
	{
		if (cheap->position == 1 && cheap->target->position == 1)
			rr(a, b);
		else if (cheap->position == 2 && cheap->target->position == 2)
			rrr(a, b);
	}
}

void	rotate_to_top(t_nodestack **a, t_nodestack **b, t_nodestack *cheapest)
{
	while (*a != cheapest->target)
	{
		if (cheapest->target->position == 1)
			ra(a);
		else if (cheapest->target->position == 2)
			rra(a);
	}
	while (*b != cheapest)
	{
		if (cheapest->position == 1)
			rb(b);
		else if (cheapest->position == 2)
			rrb(b);
	}
}

void	move_nodes(t_nodestack **a, t_nodestack **b)
{
	t_nodestack	*cheapest;

	if (!*a || !*b)
		return ;
	cheapest = get_cheapest(*b);
	if ((cheapest->position == 1 && cheapest->target->position == 1)
		|| (cheapest->position == 2 && cheapest->target->position == 2))
		rotate_both(a, b, cheapest);
	rotate_to_top(a, b, cheapest);
	pa(b, a);
}


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
