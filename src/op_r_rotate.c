/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:27:47 by wweerasi          #+#    #+#             */
/*   Updated: 2025/02/07 17:10:21 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	r_rotate(int *to, int *from, int len)
{
	int	tmp;

	tmp = *(from + (len - 1));
	ft_memmove(to, from, (len - 1) * sizeof(int));
	*from = tmp;
}

void	rra(t_stack *stack)
{
	r_rotate((stack -> a) + 1, stack -> a, stack -> len_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *stack)
{
	r_rotate((stack -> b) + 1, stack -> b, stack -> len_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack *stack)
{
	r_rotate((stack -> a) + 1, stack -> a, stack -> len_a);
	r_rotate((stack -> b) + 1, stack -> b, stack -> len_b);
	ft_putendl_fd("rrr", 1);
}
