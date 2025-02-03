/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:14:15 by wweerasi          #+#    #+#             */
/*   Updated: 2025/02/03 22:04:07 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	init_stacks(int size, t_stack *stack)
{
	stack -> a = NULL;
	stack -> b = NULL;
	stack -> a = malloc(size * sizeof(int));
	if (stack -> a)
		stack -> b = malloc(size * sizeof(int));
	if (!stack -> b)
	{
		if (stack -> a)
			free(stack -> a);
		return (1);
	}
	stack -> len_a = 0;
	stack -> len_b = 0;
	return (0);
}


void	stack_normalize(int size, t_node *inp, t_stack *stack)
{
	t_node	*inp_i;
	t_node	*inp_j;
	int		rank;
	int	*tmp;
	
	if (init_stacks(size, stack))
		exit_push_swap(NULL, NULL, &inp);
	inp_i = inp;
	tmp = stack -> a;
	while(inp_i)
	{

		rank = 0;
		inp_j = inp;
		while (inp_j)
		{
			if (inp_i -> num > inp_j -> num)
				rank++;
			inp_j = inp_j -> next;
		}
		*tmp = rank;
		tmp++;
		inp_i = inp_i -> next;
		stack -> len_a++;
	}
}
