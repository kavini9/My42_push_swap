/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:14:15 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/24 18:18:42 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	init_stack(int size, t_node *inp, t_stack *stack)
{
	t_node	tmp;

	i = 0;
	tmp = stack;
	stack_size = ft_stacksize(stack);
	a = malloc(stack_size + 1);
	if (!a)
		exit_push_swap(&stack);
	while(i <= stack_size)
	{
		rank = 0;
		while (stack)
			if (stack -> c 
