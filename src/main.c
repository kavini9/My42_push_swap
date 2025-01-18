/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:34:56 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/18 16:00:00 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*tmp;

	stack_a = NULL;
	if (ac <= 2)
		return (EXIT_SUCCESS);
	if (!is_valid_arg(av + 1))
		return (printf("error()\n"));
	arg_parse(av + 1, &stack_a);
	tmp = stack_a;
	while (tmp)
	{
		printf("%i : %i\n", tmp -> rank, tmp -> num);
		tmp = tmp -> next;
	}
	exit_push_swap(&stack_a);
	return (0);
}
