/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:34:56 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/27 18:09:53 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_node	*inp;
	t_stack	*stack;
	int		stack_size;

	inp = NULL;
	if (ac < 2)
		return (EXIT_SUCCESS);
	if (!is_valid_arg(av + 1))
		return (write(1,"Error\n",7));
	stack_size = arg_parse(av + 1, &inp); 
	if (stack_size == 1 || is_sorted(inp))
		exit_push_swap(NULL, &inp);
	stack_normalize(stack_size, inp, &stack); 
	radix_sort(&stack);

	
	int i;

	i = 0;
	while (i < stack -> len_a)
	{
		printf("%i	- %i\n", i, stack -> a[i]);
		i++;
	}
	exit_push_swap(NULL, &inp);
	return (0);

	

/*	tmp = stack;
	while (tmp)
	{
		printf("%i : %i\n", tmp -> index, tmp -> num);
		tmp = tmp -> next;
	}
	exit_push_swap(&stack);
	return (0);
*/
}
