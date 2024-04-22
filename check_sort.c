/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:52:58 by gmersch           #+#    #+#             */
/*   Updated: 2024/04/22 18:00:32 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_lst_sort(t_vars *list_a)
{
	t_vars	*buffer;

	buffer = list_a;
	while (buffer->next)
	{
		if (buffer->id > buffer->next->id)
			return (1);
		buffer = buffer->next;
	}
	return (0);
}
