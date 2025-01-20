/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:34:56 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/20 19:21:22 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack;
	t_node	*tmp;
//	int		stack_size;
//	int		*a;
//	int		*b;

	stack = NULL;
	if (ac < 2)//wrong condition wht if all numbers in a one long string?
		return (EXIT_SUCCESS);
	if (!is_valid_arg(av + 1))
		return (printf("Error\n"));
	arg_parse(av + 1, &stack);
	//stack_size = ft_stacksize(stack);
//	stack_size = initiate_stack_a(a, stack);
//	if (stack_size = 1)

	exit_push_swap(&stack);

	tmp = stack;
	while (tmp)
	{
		printf("%i : %i\n", tmp -> rank, tmp -> num);
		tmp = tmp -> next;
	}
	exit_push_swap(&stack);
	return (0);
}
