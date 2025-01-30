/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:12:50 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/30 22:51:12 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_push_swap(char *param, t_node **stack_a)
{
	if (param)
		ft_putendl_fd(param, 1);
	ps_lstclear(stack_a);
	exit(EXIT_FAILURE);
}
