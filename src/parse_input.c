/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:35:23 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/17 19:32:06 by wweerasi         ###   ########.fr       */
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
	printf("created a new node: %i\n", new_node -> num);
	if (!*stack_a)
	{
		*stack_a = new_node;
		printf("initialized stack_a with first node: %i\n", (*stack_a) -> num);
	}
	else
	{
		ft_stackadd_back(stack_a, new_node);
		printf("added a node to stack_a: %i\n", ft_stacklast(*stack_a) -> num);
	}
}

t_node	*arg_parse(char **inp)
{
	int		rank;
	int		num;
	char	**split_inp;
	char	**tmp;
	t_node	*stack_a;

	rank = 0;
	stack_a = NULL;
	while (*inp)
	{
		printf("before split\n");
		split_inp = ft_split(*inp, ' ');
		printf("after split\n");
		if (!split_inp)
			exit_push_swap(&stack_a);
		printf("split ok\n");
		tmp = split_inp;
		while (*tmp)
		{
			printf("tmp: %s	", *tmp);
			num = ft_atoi(*tmp);
			printf("num: %i\n", num);
			if (((num == 0 || num == -1) && ft_strlen(*tmp) > 9)
			|| is_duplicate(num, stack_a))
			{
				free_arr(&tmp);
				exit_push_swap(&stack_a);
			}
			stack_appendnum(&stack_a, num, rank);
			rank++;
			tmp++;
		}
		free_arr(&split_inp);
		inp++;
	}
	return(stack_a);

}
