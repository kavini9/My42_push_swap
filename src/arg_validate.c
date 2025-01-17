/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:35:07 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/17 10:41:27 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_empty(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (!((*str >= 9 && *str <= 13) || *str == ' '))
			return (0);
		str++;
	}
	return (1);
}

static int	is_valid_multi(char *inp)
{
	while (*inp)
	{
		while (((*inp >= 9 && *inp <= 13) || *inp == ' ') && *(inp + 1))
			inp++;
		if (*inp == '+' || *inp == '-')
		{
			if (*(inp + 1) && ft_isdigit(*(inp + 1)))
				inp++;
			else
				return (0);
		}
		while (*inp && !((*inp >= 9 && *inp <= 13) || *inp == ' '))
		{
			if (!ft_isdigit(*inp))
				return (0);
			inp++;
		}
		if (((*inp >= 9 && *inp <= 13) || *inp == ' ') && !*(inp + 1))
			inp++;
	}
	return (1);
}

static int	is_valid_single(char *inp)
{
	while (((*inp >= 9 && *inp <= 13) || *inp == ' ') && *(inp + 1))
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

int	is_valid_arg(char **inp)
{
	while (*inp)
	{
		if (is_empty(*inp))
			return (0);
		if (!is_valid_single(*inp))
		{
			if (!is_valid_multi(*inp))
				return (0);
		}
		inp++;
	}
	return (1);
}
