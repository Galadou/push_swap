/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:12:51 by gmersch           #+#    #+#             */
/*   Updated: 2024/04/22 17:18:03 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_and_free(char *error, t_vars *lst, char **tab_arg)
{
	t_vars	*buffer;

	free_tab(tab_arg);
	if (!lst)
	{
		ft_putstr_fd(error, 2);
		exit (EXIT_FAILURE);
	}
	while (lst->next)
	{
		buffer = lst->next;
		free(lst);
		lst = buffer;
	}
	free(lst);
	ft_putstr_fd(error, 2);
	exit (EXIT_FAILURE);
}

static int	is_error(const char *nptr, long int *nb, int negat)
{
	int	i;

	i = 0;
	while (ft_isdigit(nptr[i]))
	{
		*nb = *nb * 10 + (nptr[i] - 48);
		i++;
	}
	if (nptr[i] != '\0' || *nb * negat > 2147483647 || \
				*nb * negat < -2147483648)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr, t_vars *lst, char **tab_arg)
{
	long int	nb;
	int			negat;
	int			count_sign;

	count_sign = 0;
	negat = 1;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	while (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			negat = -1;
		count_sign++;
		if (count_sign > 1 || ft_isdigit(*(nptr + 1)) != 1)
			error_and_free("Error\n", lst, tab_arg);
		nptr++;
	}
	nb = 0;
	if (is_error(nptr, &nb, negat) == 1)
		error_and_free("Error\n", lst, tab_arg);
	return (nb * negat);
}
