/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:28:03 by wweerasi          #+#    #+#             */
/*   Updated: 2025/02/07 14:19:54 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(int *to, int *from, int len)
{
	int	tmp;

	tmp = *to;
	ft_memmove(to, from, (len - 1) * sizeof(int));
	*(to + (len - 1)) = tmp;
}

void	ra(t_stack *stack)
{
	rotate(stack -> a, (stack -> a) + 1, stack -> len_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack *stack)
{
	rotate(stack -> b, (stack -> b) + 1, stack -> len_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack *stack)
{
	rotate(stack -> a, (stack -> a) + 1, stack -> len_a);
	rotate(stack -> b, (stack -> b) + 1, stack -> len_b);
	ft_putendl_fd("rr", 1);
}
