/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterflies.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 03:32:10 by gmersch           #+#    #+#             */
/*   Updated: 2024/04/22 17:02:09 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	butterflies_to_a(t_vars **list_a, t_vars **list_b)
{
	int		need_swap_a;

	need_swap_a = 0;
	while (*list_b)
	{
		if ((*list_b)->id == lstlen(*list_b) - 1 && need_swap_a == 0)
		{
			push_b(list_b, list_a);
			need_swap_a = 1;
		}
		if (way_to_bigger(*list_b) == '0')
		{
			push_b(list_b, list_a);
			if (need_swap_a == 1)
				swap_stacks(list_a, 'a');
			need_swap_a = 0;
		}
		else if (way_to_bigger(*list_b) == 'u')
			rotate_list(list_b, 'b');
		else if (way_to_bigger(*list_b) == 'd')
			reverse_rotate_b(list_b, 1);
		else
			break ;
	}
}

void	bflies_to_b(t_vars **list_a, t_vars **list_b, int nb_arg, int nb_chunk)
{
	int		i;
	char	way;

	i = 1;
	while (i - 3 < nb_chunk)
	{
		way = way_to_rotate(*list_a, i * (nb_arg / nb_chunk));
		while (way == 'u' || way == 'd' || way == '0')
		{
			if (way == '0')
			{
				push_a(list_a, list_b);
				if ((*list_b)->id > (i * (nb_arg / nb_chunk)) - \
					((nb_arg / nb_chunk) / 2))
					rotate_list(list_b, 'b');
			}
			else
				rotate_list(list_a, 'a');
			if (*list_a == NULL)
				break ;
			way = way_to_rotate(*list_a, i * (nb_arg / nb_chunk));
		}
		i++;
	}
	butterflies_to_a(list_a, list_b);
}
