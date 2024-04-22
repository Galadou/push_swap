/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 03:28:56 by gmersch           #+#    #+#             */
/*   Updated: 2024/04/22 03:28:58 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_vars	*create_a(char **tab_arg)
{
	int		id;
	t_vars	*lst;
	t_vars	*head;
	t_vars	*buffer;

	id = 0;
	lst = NULL;
	buffer = NULL;
	lst = ft_lstnew_vars(ft_atoi(tab_arg[id], lst, tab_arg), id);
	head = lst;
	id++;
	lst->next = NULL;
	while (tab_arg[id])
	{
		buffer = ft_lstnew_vars(ft_atoi(tab_arg[id], head, tab_arg), 0);
		lst->next = buffer;
		lst = lst->next;
		lst->next = NULL;
		id++;
	}
	lst->next = NULL;
	free_tab(tab_arg);
	is_2arg_are_same(head);
	return (head);
}
