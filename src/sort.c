/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:21:37 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/27 15:11:50 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	count_bits(int num)
{
	int	count;

	count = 0;
	while (num)
	{
		count++;
		num >>= 1;
	}
	return (count);
}

void sort(t_stack *stack)
{
	int iter;

	iter = count_bits(stack -> len_a);
	while (iter
