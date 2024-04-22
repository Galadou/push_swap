/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:55:02 by gmersch           #+#    #+#             */
/*   Updated: 2024/04/22 16:24:18 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_vars	*list_a;
	t_vars	*list_b;
	char	**tab_arg;
	int		nb_arg;

	nb_arg = 0;
	check_arg(argc, argv); //check de base comme argc > 1
	tab_arg = argv_to_tab(argv); //je recuperer tout les arg dans un tab
	list_a = create_a(tab_arg); // je cree ma list chaine a partir du tab
	nb_arg = lstlen(list_a);
	if (nb_arg == 1)
	{
		free_list(list_a);
		exit (EXIT_SUCCESS);
	}
	//printf ("%d = nb arg\n", nb_arg);
	/*t_vars	*test;
	test = list_a;
	printf("\nLISTE A APRES =\n\n");
	while (test)
	{
		printf("%d = nb\n%d = id\n\n", test->nb, test->id);
		test = test->next;
	}*/
	list_b = NULL;
	set_id(list_a, nb_arg);
	/*is_list_sort(list_a, list_b);
	ERROR DEDANS small_stack_sort(list_a, nb_arg);//je tri les petites piles avec peu d'arg a trier
	is_list_sort(list_a, list_b);
	printf("\nLISTE A AVANT =\n\n");
	test = list_a;
	while (test)
	{
		printf("%d = nb\n%d = id\n\n", test->nb, test->id);
		test = test->next;
	}*/
	find_chunk_and_bflies(&list_a, &list_b, nb_arg);
	//is_list_sort(list_a, list_b);



	/*test = list_b;
	printf("\n\nLISTE B =\n");
	while (test)
	{
		printf("%d = nb\n%d = id\n\n", test->nb, test->id);
		test = test->next;
	}
	printf("\n");

	test = list_a;
	printf("\nLISTE A APRES =\n\n");
	while (test)
	{
		printf("%d = nb\n%d = id\n\n", test->nb, test->id);
		test = test->next;
	}
	free_list(test);*/
	free_list(list_b);

	free_list(list_a);
	return (0);
}
