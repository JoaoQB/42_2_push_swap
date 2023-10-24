/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:30:48 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/10/24 14:40:45 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // Memory allocation
# include <stddef.h> // Types and macros like NULL and size_t
# include <limits.h> // Limits
# include <stdbool.h> // boolean types and values
# include <unistd.h> // System calls, write

/* Stack structure*/
typedef struct s_nodestack
{
	int	value;
	int	index;
	struct s_nodestack	*next;
	struct s_nodestack	*previous;
} t_nodestack;

/* Input validation and stack creation*/
long	ft_atoi(const char	*string);
t_nodestack *create_node(int index, int value);

#endif
