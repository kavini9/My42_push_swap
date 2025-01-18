/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:35:23 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/18 15:59:51 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_arr(char ***arr)
{
	char	**tmp;

	tmp = *arr;
	if (!tmp)
		return ;
	while (*tmp)
	{
		free(*tmp);
		*tmp = NULL;
		tmp++;
	}
	free(*arr);
	*arr = NULL;
}

static int	is_duplicate(int num, t_node *a)
{
	while (a != NULL)
	{
		if (num == a -> num)
			return (1);
		else
			a = a -> next;
	}
	return (0);
}

void	stack_appendnum(t_node **stack_a, int num, int rank)
{
	t_node	*new_node;

	new_node = ft_stacknew(num, rank);
	if (!*stack_a)
		*stack_a = new_node;
	else
		ft_stackadd_back(stack_a, new_node);
}

void	arg_parse(char **inp, t_node **stack_a)
{
	int		rank;
	long int		num;
	char		**split_inp;
	char		**tmp;

	rank = 0;
	while (*inp)
	{
		split_inp = ft_split(*inp, ' ');
		if (!split_inp)
			exit_push_swap(stack_a);
		tmp = split_inp;
		while (*tmp)
		{
			num = ft_atol(*tmp);
			if ((((num == 0 || num == -1) && ft_strlen(*tmp) > 19)
			|| (num > 2147483647 || num < -2147483648))
			|| is_duplicate(num, *stack_a))
			{
				free_arr(&tmp);
				exit_push_swap(stack_a);
			}
			stack_appendnum(stack_a, num, rank);
			rank++;
			tmp++;
		}
		free_arr(&split_inp);
		inp++;
	}
}
