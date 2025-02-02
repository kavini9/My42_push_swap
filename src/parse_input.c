/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:35:23 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/30 19:11:35 by wweerasi         ###   ########.fr       */
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

void	stack_appendnum(t_node **stack, int num, int index)
{
	t_node	*new_node;

	new_node = ps_stacknew(num, index);
	if (!*stack)
		*stack = new_node;
	else
		ps_stackadd_back(stack, new_node);
}

int	arg_parse(char **inp, t_node **stack)
{
	int		index;
	long int		num;
	char		**split_inp;
	char		**tmp;

	index = 0;
	while (*inp)
	{
		split_inp = ft_split(*inp, ' ');
		if (!split_inp)
			exit_push_swap(NULL, stack);
		tmp = split_inp;
		while (*tmp)
		{
			num = ft_atol(*tmp);
			if ((((num == 0 || num == -1) && ft_strlen(*tmp) >= 19)
			|| (num > 2147483647 || num < -2147483648))
			|| is_duplicate(num, *stack)) // check if 19 is correct 
			{
				free_arr(&tmp);// there's a double free or corruption and core dumped aborted error when duplicates
				exit_push_swap("Error",stack);
			}
			stack_appendnum(stack, num, index);
			index++;
			tmp++;
		}
		free_arr(&split_inp);
		inp++;
	}
	return (index);
}
