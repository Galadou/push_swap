/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_id.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 03:26:34 by gmersch           #+#    #+#             */
/*   Updated: 2024/04/22 03:26:45 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_id(t_vars *list_a, int nb_arg)
{
	t_vars	*buffer;
	t_vars	*head;
	int		i;

	i = 1;
	head = list_a;
	while (i != nb_arg + 1)
	{
		list_a = head;
		while (list_a->id != 0)
			list_a = list_a->next;
		buffer = list_a;
		while (list_a)
		{
			if (list_a->nb < buffer->nb && list_a->id == 0)
				buffer = list_a;
			list_a = list_a->next;
		}
		buffer->id = i;
		i++;
	}
	list_a = head;
}
