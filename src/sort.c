/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:21:37 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/30 22:43:44 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ra(t_stack *stack)
{
	int	*top_a;
	int	tmp;

	top_a = stack -> a;
	tmp = *top_a;
//	printf("top_a in ra = %d\n", *top_a);
	ft_memmove(top_a, top_a + 1, ((stack -> len_a) - 1) * sizeof(int));
//	ft_putendl_fd("memmove done", 1);
	stack -> a[stack -> len_a - 1] = tmp;
//	printf("top_a in ra after ra= %d\n", *top_a);
	ft_putendl_fd("ra", 1);
}

static void	push(int *from, int *to, int *len_from, int *len_to)
{
//	ft_putendl_fd("we are in push", 1);
	if (*len_to > 0)
		ft_memmove((to + 1), to, (*len_to) * sizeof(int));
//	ft_putendl_fd("push_memmove_1 done", 1);
	ft_memmove(to, from, sizeof(int));
//	ft_putendl_fd("push_memmove_2 done", 1);
	if (*len_from > 1)
		ft_memmove(from, from + 1, (*len_from - 1) * sizeof(int));
//	ft_putendl_fd("push_memmove_3 done", 1);
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
	int	len_a;
	
	iter = 0;
	bit_mask = 1;
	len_a = stack -> len_a;
	while (len_a && ++iter)
		len_a >>= 1;
	while (iter--)
	{
		len_a = stack -> len_a;
		while (len_a--)
		{
/*			printf("len_a = %d      - iter = %d     -  bit mask = %d\n",len_a, iter, bit_mask);
			if (stack -> len_a > 0)
				printf("top_a = %d	", *(stack -> a));
			if (stack -> len_b > 0)
                                printf("top_b = %d", *(stack-> b));
			printf("\n");*/
			if ((*(stack -> a) & bit_mask) && stack -> len_a > 1)
				ra(stack);
			else
				pb(stack);
		}
//		printf("len_b = %d\n", stack -> len_b);printf("len_b = %d\n", stack -> len_b);
		while (stack -> len_b > 0)
			pa(stack);
//		int i = 0;
//	      	while (i < stack -> len_a)
//        	{
//                	printf("%i      - %i\n", i, stack -> a[i]);
//                	i++;
//        	}
		bit_mask <<= 1;
	}
}
