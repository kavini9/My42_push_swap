/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:12:50 by wweerasi          #+#    #+#             */
/*   Updated: 2025/02/03 22:24:01 by wweerasi         ###   ########.fr       */
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

void	exit_push_swap(char *param, char ***arr, t_node **stack)
{
	if (param)
		ft_putendl_fd(param, 2);
	if (arr)
                free_arr(arr);
	ps_lstclear(stack);
	exit(EXIT_FAILURE);
}
