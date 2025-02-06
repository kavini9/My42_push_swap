/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:35:23 by wweerasi          #+#    #+#             */
/*   Updated: 2025/02/03 22:06:39 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_duplicate(int num, int index, int *stack)
{
	int 	i;

	i = 0;
	while (i < index)
	{
		if (num == *(stack + i))
			return (1);
		else
			i++;
	}
	return (0);
}

void	arg_parse(int index, char **inp, int *stack)
{
	long int		num;
	char		**split_inp;
	char		**tmp;

	while (*inp)
	{
		split_inp = ft_split(*inp, ' ');
		if (!split_inp)
			exit_push_swap(NULL, NULL, &stack);
		tmp = split_inp;
		while (*tmp)
		{
			num = ft_atol(*tmp);
			if ((((num == 0 || num == -1) && ft_strlen(*tmp) >= 19)
			|| (num > 2147483647 || num < -2147483648))
			|| is_duplicate(num, index, stack)) // check if 19 is correct 
				exit_push_swap("Error", &split_inp, &stack);
			*(stack + index) = num;
			tmp++;
			index++;
		}
		free_arr(&split_inp);
		inp++;
	}
}
