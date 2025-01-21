/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:14:15 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/21 12:21:06 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	initiate_stack_a(int *a, t_node *stack)
{
	int		stack_size;
	int		rank;
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
