/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:21:37 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/30 22:57:22 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ra(t_stack *stack)
{
	int	*top_a;
	int	tmp;

	top_a = stack -> a;
	tmp = *top_a;
	ft_memmove(top_a, top_a + 1, ((stack -> len_a) - 1) * sizeof(int));
	stack -> a[stack -> len_a - 1] = tmp;
	ft_putendl_fd("rb", 1);
}

static void	rb(t_stack *stack)
{
	int	*top_b;
	int	tmp;

	top_b= stack -> b;
	tmp = *top_b;
	ft_memmove(top_b, top_b + 1, ((stack -> len_b) - 1) * sizeof(int));
	stack -> b[stack -> len_b - 1] = tmp;
	ft_putendl_fd("ra", 1);
}

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

static void	pa(t_stack *stack)
{
	push(stack -> b, stack -> a, &stack -> len_b, &stack -> len_a);
	ft_putendl_fd("pa", 1);
}

static void     pb(t_stack *stack)
{
        push(stack -> a, stack -> b, &stack -> len_a, &stack -> len_b);
        ft_putendl_fd("pb", 1);
}

void radix_sort(t_stack *stack)
{
	int	iter;
	int	bit_mask;
	int	len;
	
	iter = 0;
	bit_mask = 1;
	len =stack -> len_a;
	while (len && ++iter)
		len >>= 1;
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
			if (*(stack -> b) & (bit_mask * 2))
				pa(stack);
			else
				rb(stack);
		}
		bit_mask <<= 1;
	}
}
