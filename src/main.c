/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:34:56 by wweerasi          #+#    #+#             */
/*   Updated: 2025/02/03 22:02:03 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_node	*inp;
	t_stack	stack;
	int		stack_size;

	inp = NULL;
	stack_size = 0;
	if (ac < 2)
		return (EXIT_SUCCESS);
	if (!is_valid_arg(av + 1))
		return (write(1,"Error\n",7));
	arg_parse(&stack_size, av + 1, &inp); 
	if (stack_size == 1 || is_sorted(inp))
		exit_push_swap(NULL, NULL, &inp);
	stack_normalize(stack_size, inp, &stack);


//	int i;
/*	
	i = 0;
	while (i < stack_size)
	{
		printf("%d - %d\n", i, stack.a[i]);
		i++;
	}
	printf("len_a = %d	len_b = %d\n", stack.len_a, stack.len_b);
*/

	radix_sort(stack_size, &stack);

/*	
	i = 0;
	while (i < stack_size)
	{
		printf("%d - %d\n", i, stack.a[i]);
		i++;
	}
	printf("len_a = %d	len_b = %d\n", stack.len_a, stack.len_b);
*/
	free(stack.a);
	free(stack.b);	
	exit_push_swap(NULL, NULL, &inp);
	return (0);

}
