/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:52:23 by gmersch           #+#    #+#             */
/*   Updated: 2024/04/22 04:28:46 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stacks(t_vars **list, char c)
{
	int		tmp_nb;
	int		tmp_id;
	t_vars	*buffer;

	if (*list != NULL)
	{
		buffer = *list; //buffer change le contenu de *list patron
		if (buffer->next && buffer->nb)
		{
			tmp_nb = buffer->next->nb;
			tmp_id = buffer->next->id;
			buffer->next->nb = buffer->nb;
			buffer->next->id = buffer->id;
			buffer->nb = tmp_nb;
			buffer->id = tmp_id;
			if (c == 'a')
				write(1, "sa\n", 3);
			else if (c == 'b')
				write(1, "sb\n", 3);
		}
	}
}

void	swap_both(t_vars **list_a, t_vars **list_b)
{
	swap_stacks(list_a, 0);
	swap_stacks(list_b, 0);
	write (1, "ss\n", 3); // est ce que si qu'une s'est faites faut marque sa ou quand meme ss
}

void	push_a(t_vars **list_a, t_vars **list_b)
{
	t_vars	*head_a;
	t_vars	*head_b;

	head_a = *list_a;
	head_b = *list_b;
	*list_b = ft_lstnew_vars((*list_a)->nb, (*list_a)->id);//cree nv maillon
	(*list_b)->next = head_b;//nv maillon->next egale a la chaine b
	*list_a = (*list_a)->next; //list a = maillon d'apres
	head_a->next = NULL; //on sup le 1er maillon vu quil a deja ete copie dans b
	free(head_a);
	write(1, "pb\n", 3);
}

void	push_b(t_vars **list_b, t_vars **list_a)
{
	t_vars	*head_a;
	t_vars	*head_b;

	head_a = *list_a;
	head_b = *list_b;
	*list_a = ft_lstnew_vars((*list_b)->nb, (*list_b)->id);//cree nv maillon
	(*list_a)->next = head_a;//nv maillon->next egale a la chaine a
	*list_b = (*list_b)->next; //list b = maillon d'apres
	head_b->next = NULL; //on sup le 1er maillon vu quil a deja ete copie dans b
	free(head_b);
	write(1, "pa\n", 3);
}

void	rotate_list(t_vars **list, char c)
{
	t_vars	*end_list;
	t_vars	*head;

	end_list = *list;
	head = *list;
	if (*list != NULL)
	{
		while (end_list->next)
			end_list = end_list->next;
		end_list->next = head;
		*list = (*list)->next;
		head->next = NULL;
		if (c == 'a')
			write(1, "ra\n", 3);
		if (c == 'b')
			write(1, "rb\n", 3);
	}
}
