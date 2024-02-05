/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:26:31 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/12/12 18:44:02 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_error("Error\n", stack, argv, argc);
	first = create_stack(argv, stack, argc);
	ft_free_argv(argv);
	return (first);
}
