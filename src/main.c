/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:34:56 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/21 12:15:43 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack;
	t_node	*tmp;

	stack = NULL;
	if (ac < 2)
		return (EXIT_SUCCESS);
	if (!is_valid_arg(av + 1))
		return (write(1,"Error\n",7));
	if (arg_parse(av + 1, &stack)  == 1 || is_sorted(stack))
		exit_push_swap(&stack);
	sort(&stack);




	tmp = stack;
	while (tmp)
	{
		printf("%i : %i\n", tmp -> index, tmp -> num);
		tmp = tmp -> next;
	}
	exit_push_swap(&stack);
	return (0);
}
