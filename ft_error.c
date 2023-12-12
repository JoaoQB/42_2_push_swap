/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:45:00 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/12/12 18:13:15 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanup_and_exit(t_nodestack *a, char **argv, int argc)
{
	free_stack(a);
	if (argc == 2)
		ft_free_argv(argv);
	exit (1);
}

// void	ft_error(char *string, t_nodestack *a, char **argv, int argc)
// {
// 	write(2, string, ft_strlen(string));
// 	cleanup_and_exit(a, argv, argc);
// }

void	ft_error(char *string, t_nodestack *a, char **argv, int argc)
{
	ssize_t written;

	written = write(2, string, ft_strlen(string));
	(void)written;
	cleanup_and_exit(a, argv, argc);
}
