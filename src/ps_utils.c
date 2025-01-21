/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:26:37 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/21 11:41:22 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_node *stack)
{
	while(stack -> next)
	{
		if (stack ->  num  < stack -> next -> num)
			stack = stack -> next;
		else
			return (0);
	}
	write(1, "Sorted\n",8);
	return (1);
}
