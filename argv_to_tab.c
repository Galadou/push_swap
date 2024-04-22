/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 03:28:08 by gmersch           #+#    #+#             */
/*   Updated: 2024/04/22 04:15:32 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	need_free(char *str)
{
	if (str)
		free(str);
}

static void	malloc_error(char *str, char *str_other)
{
	if (!str)
	{
		if (str_other)
			free(str_other);
		ft_putstr_fd("Error\n", 2);
		exit (EXIT_FAILURE);
	}
}

char	**argv_to_tab(char **argv)
{
	char	*arg_join;
	char	*buffer;
	char	**tab;
	int		i;

	i = 1;
	buffer = ft_strdup(argv[1]);
	malloc_error(buffer, 0);
	while (argv[++i])
	{
		arg_join = ft_strjoin(buffer, " ");
		malloc_error(arg_join, buffer);
		need_free(buffer);
		buffer = ft_strjoin(arg_join, argv[i]);
		malloc_error(buffer, arg_join);
		need_free(arg_join);
	}
	tab = ft_split(buffer, ' ');
	if (!tab)
		malloc_error(0, buffer);
	need_free(buffer);
	return (tab);
}
