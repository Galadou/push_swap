/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 03:27:53 by gmersch           #+#    #+#             */
/*   Updated: 2024/04/22 03:35:23 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	if (tab)
	{
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	free_list(t_vars *lst)
{
	t_vars	*buffer;

	if (lst)
	{
		while (lst->next)
		{
			buffer = lst->next;
			free(lst);
			lst = buffer;
		}
		free(lst);
	}
}
