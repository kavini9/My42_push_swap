/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:12:50 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/24 17:32:40 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ps_lstclear(t_node **stack)
{
	t_node	*current;
	t_node	*tmp;

	if (stack != NULL)
	{
		current = *stack;
		while (current != NULL)
		{
			tmp = current;
			current = current -> next;
			free(tmp);
		}
		*stack = NULL;
	}
}

void	exit_push_swap(char *param, t_node **stack_a)
{
	if (param)
		ft_putendl_fd(param, 1);
	ps_lstclear(stack_a);
	exit(EXIT_FAILURE);
}
