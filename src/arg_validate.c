/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:35:07 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/24 17:16:26 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_empty(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

static int	is_valid_multi(int *count, char *inp, char *cmp)
{
	while (*inp)
	{
		while (*inp == ' ' && *(inp + 1))
			inp++;
		if (*inp == '+' || *inp == '-')
		{
			if (*(inp + 1) && ft_isdigit(*(inp + 1)))
				inp++;
			else
				return (0);
		}
		while (*inp && *inp != ' ')
		{
			if (!ft_isdigit(*inp))
				return (0);
			else if (*inp == *cmp || (*inp != *cmp
					&& (*(inp - 1) == ' ' || *(inp - 1) == '+'
						|| *(inp - 1) == '-')))
				(*count)++;
			inp++;
		}
		if (*inp == ' ' && !*(inp + 1))
			inp++;
	}
	return (*count);
}

static int	is_valid_single(char *inp)
{
	while (*inp == ' ' && *(inp + 1))
		inp++;
	if ((*inp == '+' || *inp == '-') && *(inp + 1))
		inp++;
	while (*inp)
	{
		if (!ft_isdigit(*inp))
			return (0);
		inp++;
	}
	return (1);
}

int	get_len_if_arg_valid(char **inp)
{
	int	stack_size;
	int	multi_count;

	stack_size = 0;
	while (*inp)
	{
		multi_count = 0;
		if (is_empty(*inp))
			return (0);
		if (!is_valid_single(*inp))
		{
			if (!is_valid_multi(&multi_count, *inp, *inp))
				return (0);
			else
				stack_size += multi_count;
		}
		else
			stack_size++;
		inp++;
	}
	return (stack_size);
}
