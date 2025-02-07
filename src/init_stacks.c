/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:14:15 by wweerasi          #+#    #+#             */
/*   Updated: 2025/02/07 14:23:38 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	init_stacks(int len, t_stack *stack)
{
	stack -> a = NULL;
	stack -> b = NULL;
	stack -> a = malloc(len * sizeof(int));
	if (stack -> a)
		stack -> b = malloc(len * sizeof(int));
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

void	stack_normalize(int len, int *inp, t_stack *stack)
{
	int	i;
	int	j;
	int	rank;
	int	*tmp;

	if (init_stacks(len, stack))
		exit_push_swap(NULL, NULL, &inp);
	tmp = stack -> a;
	i = 0;
	while (i < len)
	{
		rank = 0;
		j = 0;
		while (j < len)
		{	
			if (*(inp + i) > *(inp + j))
				rank++;
			j++;
		}
		*tmp = rank;
		tmp++;
		i++;
		(stack -> len_a)++;
	}
}
