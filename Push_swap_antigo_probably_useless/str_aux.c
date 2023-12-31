/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:26:31 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/11/24 15:18:57 by jqueijo-         ###   ########.fr       */
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

t_nodestack	*single_argv(char **argv)
{
	t_nodestack	*first;

	if (!argv)
		return (NULL);
	argv = ft_split(*argv, ' ');
	if (!*argv)
		exit(1);
	first = create_stack(argv);
	ft_free_argv(argv);
	return (first);
}
