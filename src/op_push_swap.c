/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:55:36 by wweerasi          #+#    #+#             */
/*   Updated: 2025/02/07 17:12:40 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(int *from, int *to, int *len_from, int *len_to)
{
	if (*len_to > 0)
		ft_memmove((to + 1), to, (*len_to) * sizeof(int));
	ft_memmove(to, from, sizeof(int));
	if (*len_from > 1)
		ft_memmove(from, from + 1, (*len_from - 1) * sizeof(int));
	(*len_to)++;
	(*len_from)--;
}

void	pa(t_stack *stack)
{
	push(stack -> b, stack -> a, &stack -> len_b, &stack -> len_a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack *stack)
{
	push(stack -> a, stack -> b, &stack -> len_a, &stack -> len_b);
	ft_putendl_fd("pb", 1);
}

void	sa(t_stack *stack)
{
	int	tmp;

	tmp = *stack -> a;
	*stack -> a = *(stack -> a + 1);
	*(stack -> a + 1) = tmp;
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack *stack)
{
	int	tmp;

	tmp = *stack -> b;
	*stack -> b = *(stack -> b + 1);
	*(stack -> b + 1) = tmp;
	ft_putendl_fd("sb", 1);
}
