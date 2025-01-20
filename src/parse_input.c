/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:35:23 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/20 17:37:48 by wweerasi         ###   ########.fr       */
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

static int	is_duplicate(int num, t_node *node)
{
	while (node != NULL)
	{
		if (num == node -> num)
			return (1);
		else
			node = node -> next;
	}
	return (0);
}

void	stack_appendnum(t_node **stack, int num, int rank)
{
	t_node	*new_node;

	new_node = ft_stacknew(num, rank);
	if (!*stack)
		*stack = new_node;
	else
		ft_stackadd_back(stack, new_node);
}

void	arg_parse(char **inp, t_node **stack)
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
			exit_push_swap(stack);
		tmp = split_inp;
		while (*tmp)
		{
			num = ft_atol(*tmp);
			printf("ft_atol num: %li\n", num);
			if ((((num == 0 || num == -1) && ft_strlen(*tmp) >= 19)
			|| (num > 2147483647 || num < -2147483648))
			|| is_duplicate(num, *stack)) // check if 19 is correct
			{
				free_arr(&tmp);
				exit_push_swap(stack);
			}
			stack_appendnum(stack, num, rank);
			rank++;
			tmp++;
		}
		free_arr(&split_inp);
		inp++;
	}
}
