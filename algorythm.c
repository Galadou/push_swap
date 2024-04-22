/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 03:27:40 by gmersch           #+#    #+#             */
/*   Updated: 2024/04/22 17:16:37 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	way_to_rotate(t_vars *list_a, int id_max)
{
	t_vars	*buffer;
	int		i;

	i = 0;
	buffer = list_a;
	while (buffer)
	{
		if (buffer->id <= id_max)
		{
			if (i == 0)
				return ('0');
			if (i <= lstlen(list_a) / 2)
				return ('u');
			if (i >= lstlen(list_a) / 2)
				return ('d');
		}
		buffer = buffer->next;
		i++;
	}
	return ('E');
}

static char	way_find_char(t_vars *buffer, int index, int i)
{
	if (buffer->id == index)
	{
		if (i == 0)
			return ('0');
		if (i <= index / 2)
			return ('u');
		if (i >= index / 2)
			return ('d');
	}
	return ('E');
}

char	way_to_bigger(t_vars *list_b)
{
	t_vars	*buffer;
	int		i;
	int		bigger_find;

	i = 0;
	bigger_find = 0;
	buffer = list_b;
	while (buffer)
	{
		if (buffer->id > bigger_find)
			bigger_find = buffer->id;
		buffer = buffer->next;
	}
	buffer = list_b;
	while (buffer)
	{
		if (way_find_char(buffer, bigger_find, i) != 'E')
			return (way_find_char(buffer, bigger_find, i));
		buffer = buffer->next;
		i++;
	}
	return ('E');
}

char	way_to_smaller(t_vars *list_b)
{
	t_vars	*buffer;
	int		i;
	int		smaller_find;

	i = 0;
	smaller_find = lstlen(list_b) + 2;
	buffer = list_b;
	while (buffer)
	{
		if (buffer->id < smaller_find)
			smaller_find = buffer->id;
		buffer = buffer->next;
	}
	buffer = list_b;
	while (buffer)
	{
		if (way_find_char(buffer, smaller_find, i) != 'E')
			return (way_find_char(buffer, smaller_find, i));
		buffer = buffer->next;
		i++;
	}
	return ('E');
}

void	find_chunk_and_bflies(t_vars **list_a, t_vars **list_b, int nb_arg)
{
	if (nb_arg == 2)
	{
		if ((*list_a)->id > (*list_a)->next->id)
			swap_stacks(list_a, 'a');
	}
	else if (nb_arg == 3)
		sort_3_nb(list_a);
	else if (nb_arg == 4)
		sort_4_nb(list_a, list_b);
	else if (nb_arg <= 5)
		sort_5_nb(list_a, list_b);
	else if (nb_arg <= 100)
		bflies_to_b(list_a, list_b, nb_arg, 4);
	else if (nb_arg <= 300)
		bflies_to_b(list_a, list_b, nb_arg, 5);
	else if (nb_arg <= 500)
		bflies_to_b(list_a, list_b, nb_arg, 8);
	else if (nb_arg > 500)
		bflies_to_b(list_a, list_b, nb_arg, 8);
}
