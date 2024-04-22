/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 03:28:24 by gmersch           #+#    #+#             */
/*   Updated: 2024/04/22 17:00:36 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_2arg_are_same(t_vars *lst)
{
	t_vars	*buffer_stable;
	t_vars	*buffer_check;
	t_vars	*buffer_i;

	buffer_stable = lst;
	buffer_i = lst;
	buffer_check = lst->next;
	while (buffer_check)
	{
		buffer_i = buffer_stable;
		while (buffer_i != buffer_check)
		{
			if (buffer_i->nb == buffer_check->nb)
			{
				ft_putstr_fd("Error\n", 2);
				free_list(lst);
				exit (EXIT_FAILURE);
			}
			buffer_i = buffer_i->next;
		}
		buffer_check = buffer_check->next;
	}
}

static void	check_arg_space(char **argv)
{
	int	i;
	int	x;

	i = 1;
	while (argv[i])
	{
		x = 0;
		if (argv[i][x] == ' ')
		{
			while (argv[i][x] == ' ')
				x++;
			if (ft_isdigit(argv[i][x]) != 1)
			{
				ft_putstr_fd("Error\n", 2);
				exit (EXIT_FAILURE);
			}
		}
		i++;
	}
}

void	check_arg(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit (EXIT_FAILURE);
	}
	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit (EXIT_FAILURE);
		}
		i++;
	}
	check_arg_space(argv);
}
