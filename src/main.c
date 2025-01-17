/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:34:56 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/17 19:10:10 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_node *a;
	t_node *tmp;

	if (ac <= 2)
		return(EXIT_SUCCESS);
	if (!is_valid_arg(av + 1))
		return (printf("error()\n"));
	a = arg_parse(av + 1);
	printf("returned to main\n");
	tmp = a;
	while(tmp)
	{
		printf("%i : %i\n", tmp -> rank, tmp -> num);
		tmp = tmp -> next;
	}

	return(0);
}



