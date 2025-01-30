/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:56:33 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/30 16:35:09 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ps_stacknew(int num, int index)
{
	t_node	*node_new;

	node_new = malloc(sizeof(t_node));
	if (node_new != NULL)
	{
		node_new -> num = num;
		node_new -> index = index;
		node_new -> next = NULL;
	}
	return (node_new);
}

void	ps_stackadd_back(t_node **stack, t_node *new)
{
	t_node	*last;

	if (stack == NULL || new == NULL)
		return ;
	if (*stack != NULL)
	{
		last = ps_stacklast(*stack);
		last -> next = new;
		return ;
	}
	*stack = new;
}

t_node	*ps_stacklast(t_node *stack)
{
	if (stack != NULL)
	{
		while (stack -> next != NULL)
			stack = stack -> next;
		return (stack);
	}
	return (NULL);
}

int	ps_stacksize(t_node *stack)
{
	int		count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack -> next;
	}
	return (count);
}

void     ps_lstclear(t_node **stack)
{
        t_node  *current;
        t_node  *tmp;

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

