/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:12:50 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/17 19:36:55 by wweerasi         ###   ########.fr       */
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

void	exit_push_swap(t_node **stack_a)
{
	ps_lstclear(stack_a);
	exit(EXIT_FAILURE);
}
