/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:55:18 by gmersch           #+#    #+#             */
/*   Updated: 2024/04/22 17:49:45 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_vars
{
	int				id;
	int				nb;
	struct s_vars	*next;

}	t_vars;

void	swap_stacks(t_vars **list, char c);// sa/sb
void	swap_both(t_vars **list_a, t_vars **list_b);// ss
void	push_a(t_vars **list_a, t_vars **list_b);//pa
void	push_b(t_vars **list_b, t_vars **list_a);//pb
void	rotate_list(t_vars **list, char c);//ra ou rb
void	rotate_both(t_vars **list_a, t_vars **list_b); //rr
void	reverse_rotate_a(t_vars **list_a, int c); //rra
void	reverse_rotate_b(t_vars **list_b, int c); //rrb
void	reverse_rotate_both(t_vars **list_a, t_vars **list_b); //rrr

void	set_id(t_vars *list_a, int nb_arg);

int		ft_atoi(const char *nptr, t_vars *lst, char **tab_arg);
void	check_arg(int argc, char **argv);
void	is_2arg_are_same(t_vars *lst);
void	free_tab(char **tab);
char	**argv_to_tab(char **argv);

void	free_list(t_vars *lst);
t_vars	*ft_lstnew_vars(int nb, int id);
int		lstlen(t_vars *list_a);
t_vars	*create_a(char **tab_arg);
int		is_lst_sort(t_vars *list_a);

void	find_chunk_and_bflies(t_vars **list_a, t_vars **list_b, int nb_arg);
void	sort_3_nb(t_vars **list_a);
void	sort_4_nb(t_vars **list_a, t_vars **list_b);
void	sort_5_nb(t_vars **list_a, t_vars **list_b);

void	bflies_to_b(t_vars **list_a, t_vars **list_b, int nb_arg, int nb_chunk);
char	way_to_rotate(t_vars *list_a, int id_max);
char	way_to_bigger(t_vars *list_b);
char	way_to_smaller(t_vars *list_b);

#endif
