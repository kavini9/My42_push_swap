/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:21:37 by wweerasi          #+#    #+#             */
/*   Updated: 2025/02/07 21:42:31 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_min(int cmp, t_stack *stack)
{
	int	*arr;
	int	len;

	arr = stack -> a;
	len = stack -> len_a;
	while (len--)
	{
		if (*arr < cmp)
			return (0);
		arr++;
	}
	return(1);
}

static int	is_max(int cmp, t_stack *stack)
{
	int	*arr;

	arr = stack -> a;
	while (*arr)
	{
		if (*arr > cmp)
			return (0);
		arr++;
	}
	return(1);
}


static void	sort_three(int *ar, t_stack *stack)
{
	int	i;
	int	ii;
	int	iii;

	i = *(stack -> a);
	ii = *(stack -> a + 1);
	iii = *(stack -> a + 2);
	if (is_sorted(3, stack -> a))
		return ;
	else if (i > ii && ii < iii && iii < i)
		ra(stack);
	else if (i < ii && ii > iii && (iii < i || iii > i))
		rra(stack);
	else if ((i > ii && ii < iii && iii > i)
		|| (i > ii && ii > iii && iii < i))
		sa(stack);
	sort_three(ar, stack);
}

void	simple_sort(int len, t_stack *stack)
{
	if (len == 2 && *(stack -> a) > *(stack -> a + 1))
		return (sa(stack));
	while (stack -> len_a > 3)
	{
		if (is_min(*stack -> a, stack) || is_max(*stack -> a, stack))
		{
			printf("stack -> a = %i\n" , *stack -> a);
			pb(stack);
		}
		else
			ra(stack);
	}
	sort_three(stack -> a, stack);
	while(stack -> len_b)
	{
		pa(stack);
		if (stack -> len_b && *stack -> a > *(stack -> a + 1) 
			&& !(*stack -> a > *stack -> b
			&& *stack -> b > *(stack -> a + 1)))
			ra(stack);
	}
	if (*stack -> a > *(stack -> a + 1))
		sa(stack);
	while (!is_min(*stack -> a, stack))
		ra(stack);
}

void	radix_sort(int iter, int bit_mask, int len, t_stack *stack)
{
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
}
