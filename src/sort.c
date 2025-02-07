/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:21:37 by wweerasi          #+#    #+#             */
/*   Updated: 2025/02/03 21:32:56 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void radix_sort(int len, t_stack *stack)
{
	int	iter;
	int	bit_mask;
	
	iter = 0;
	bit_mask = 1;
	while (len >> ++iter)
		;
	while (iter--)
	{
		len = stack -> len_a;
		while (len--)
		{
			if ((*(stack -> a) & bit_mask) && stack -> len_a > 1)
				ra(stack);
			else
				pb(stack);
		}
		len = stack -> len_b;
		while (len--)
		{
			if ((*(stack -> b) & (bit_mask << 1)) || !iter)
				pa(stack);
			else
				rb(stack);
		}
		bit_mask <<= 1;
	}


void	simple_sort(int len, t}
