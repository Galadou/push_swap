/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:47:10 by gmersch           #+#    #+#             */
/*   Updated: 2024/04/22 16:57:35 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_last_sort(t_vars **list_a)
{
	if ((*list_a)->next->id > (*list_a)->next->next->id)
	{
		rotate_list(list_a, 'a');
		swap_stacks(list_a, 'a');
		if (way_to_smaller((*list_a)) != '0')
			reverse_rotate_a(list_a, 1);
	}
}

void	sort_3_nb(t_vars **list_a)
{
	if ((*list_a)->next->id == 1 && (*list_a)->id > (*list_a)->next->next->id)
		rotate_list(list_a, 'a');
	if (way_to_smaller((*list_a)->next) == '0' && \
		(*list_a)->id > (*list_a)->next->id)
		swap_stacks(list_a, 'a');
	if (!(way_to_smaller(*list_a) == '0' && \
		(*list_a)->next->next->id > (*list_a)->id && \
			(*list_a)->next->next->id > (*list_a)->next->id))
	{
		if (way_to_smaller(*list_a) == '0' && \
			(*list_a)->next->id > (*list_a)->next->next->id)
		{
			swap_stacks(list_a, 'a');
			rotate_list(list_a, 'a');
		}
		else if (way_to_smaller((*list_a)->next) == '0')
			reverse_rotate_a(list_a, 1);
		else if (way_to_smaller((*list_a)->next->next) == '0' && \
			(((*list_a)->id < (*list_a)->next->id && \
				(*list_a)->id > (*list_a)->next->next->id) || \
					((*list_a)->id > (*list_a)->next->id && \
						(*list_a)->id < (*list_a)->next->next->id)))
			reverse_rotate_a(list_a, 1);
		is_last_sort(list_a);
	}
}

void	sort_4_nb(t_vars **list_a, t_vars **list_b)
{
	while (lstlen(*list_a) != 2)
	{
		if ((*list_a)->id == 1)
			push_a(list_a, list_b);
		if ((*list_a)->id == 2)
			push_a(list_a, list_b);
		if (lstlen(*list_a) != 2)
		{
			if (way_to_smaller(*list_a) == 'u')
				rotate_list(list_a, 'a');
			else if (way_to_smaller(*list_a) == 'd')
				reverse_rotate_a(list_a, 1);
		}
	}
	if ((*list_a)->id > (*list_a)->next->id)
		swap_stacks(list_a, 'a');
	if ((*list_b)->id < (*list_b)->next->id)
		swap_stacks(list_b, 'b');
	push_b(list_b, list_a);
	push_b(list_b, list_a);
}

void	sort_5_nb(t_vars **list_a, t_vars **list_b)
{
	int	before_smaller;

	before_smaller = 0;
	while (lstlen(*list_a) > 3)
	{
		if ((*list_a)->id == 2 && before_smaller == 0)
		{
			push_a(list_a, list_b);
			before_smaller = 1;
		}
		if (way_to_smaller(*list_a) == '0' && lstlen(*list_a) > 3)
			push_a(list_a, list_b);
		if (lstlen(*list_a) != 3 && way_to_smaller(*list_a) == 'u')
			rotate_list(list_a, 'a');
		if (lstlen(*list_a) != 3 && way_to_smaller(*list_a) == 'd')
			reverse_rotate_a(list_a, 1);
	}
	if ((*list_b)->id < (*list_b)->next->id)
		swap_stacks(list_b, 'b');
	sort_3_nb(list_a);
	push_b(list_b, list_a);
	push_b(list_b, list_a);
}
