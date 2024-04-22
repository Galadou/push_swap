/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rotate_and_reverse.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 03:27:10 by gmersch           #+#    #+#             */
/*   Updated: 2024/04/22 03:43:49 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_vars **list_a, t_vars **list_b)
{
	rotate_list(list_a, '0');
	rotate_list(list_b, '0');
	write(1, "rr\n", 3);
}

void	reverse_rotate_a(t_vars **list_a, int c)
{
	t_vars	*head;
	t_vars	*new_end_list;
	t_vars	*end_new_head;

	head = *list_a;
	new_end_list = *list_a;
	end_new_head = *list_a;
	if ((*list_a)->next != NULL)
	{
		while (end_new_head->next->next)
			end_new_head = end_new_head->next;
		new_end_list = end_new_head;
		end_new_head = end_new_head->next;
		new_end_list->next = NULL;
		end_new_head->next = head;
		*list_a = end_new_head;
		if (c == 1)
			write(1, "rra\n", 4);
	}
}

void	reverse_rotate_b(t_vars **list_b, int c)
{
	t_vars	*head;
	t_vars	*new_end_list;
	t_vars	*end_new_head;

	head = *list_b;
	new_end_list = *list_b;
	end_new_head = *list_b;
	if ((*list_b)->next != NULL)
	{
		while (end_new_head->next->next)
			end_new_head = end_new_head->next;
		new_end_list = end_new_head;
		end_new_head = end_new_head->next;
		new_end_list->next = NULL;
		end_new_head->next = head;
		*list_b = end_new_head;
		if (c == 1)
			write(1, "rrb\n", 4);
	}
}

void	reverse_rotate_both(t_vars **list_a, t_vars **list_b)
{
	reverse_rotate_a(list_a, 2);
	reverse_rotate_b(list_b, 2);
	write(1, "rrr\n", 4);
}
