/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 03:27:00 by gmersch           #+#    #+#             */
/*   Updated: 2024/04/22 17:44:24 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_vars	*ft_lstnew_vars(int nb, int id)
{
	t_vars	*lst;

	lst = malloc(sizeof(t_vars));
	if (!lst)
		return (NULL);
	lst->id = id;
	lst->nb = nb;
	lst->next = NULL;
	return (lst);
}

int	lstlen(t_vars *list_a)
{
	t_vars	*buffer;
	int		i;

	i = 0;
	if (!list_a)
		return (0);
	buffer = list_a;
	while (buffer)
	{
		i++;
		buffer = buffer->next;
	}
	return (i);
}
