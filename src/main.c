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
	t_stack	stack;
	int	*inp_stack;
	int		stack_len;

	inp_stack = NULL;
	stack_len = 0;
	if (ac < 2)
		return (EXIT_FAILURE);
	stack_len = get_len_if_arg_valid(av + 1);
	if (!stack_len)
		return (write(1,"Error\n",7));//beware of this return value
	inp_stack = malloc(stack_len * sizeof(int));
	if (!inp_stack)
		return (EXIT_FAILURE);
 	arg_parse(0, av + 1, inp_stack); 
	if (stack_len == 1 || is_sorted(stack_len, inp_stack))
		exit_push_swap(NULL, NULL, &inp_stack);
	stack_normalize(stack_len, inp_stack, &stack);
/*
	int i;
	
	i = 0;
	while (i < stack_len)
	{
		printf("%d - %d\n", i, stack.a[i]);
		i++;
	}
	printf("len_a = %d	len_b = %d\n", stack.len_a, stack.len_b);
*/

	radix_sort(stack_len, &stack);

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
	exit_push_swap(NULL, NULL, &inp_stack);
	return (0);

}
