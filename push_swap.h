/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:30:48 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/11/06 15:47:59 by jqueijo-         ###   ########.fr       */
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
	struct s_nodestack	*next;
	struct s_nodestack	*previous;
}	t_nodestack;

/* Debugging*/
void	print_stack(t_nodestack *lst);

/* Input validation and stack creation*/
t_nodestack	*create_node(int index, int value);
t_nodestack	*create_stack(char **argv);
long	ft_atoi(const char	*string);
void	input_char_validation(char **argv);
void	check_stack(t_nodestack *stack);
int		check_duplicate(t_nodestack *stack);
int		check_sorted(t_nodestack *stack);
char	**ft_split(char const *s, char c);

/* Error in input*/
void	ft_error(char *string);

/* Input check*/
void	input_char_validation(char **argv);
int	check_sorted(t_nodestack *stack);
int	check_duplicate(t_nodestack *stack);
void	check_stack(t_nodestack *stack);

/* Stack creation and management*/
long	ft_atoi(const char	*string);
t_nodestack	*create_node(int index, int value);
t_nodestack	*create_stack(char **argv);
void	free_stack(t_nodestack *stack);

/* String aux. functions*/
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	ft_free_argv(char **argv);
t_nodestack	*single_argv(char **argv);

/* Stack movements*/
void	sa(t_nodestack *a);
void	sb(t_nodestack *b);
void	ss(t_nodestack *a, t_nodestack *b);

#endif
