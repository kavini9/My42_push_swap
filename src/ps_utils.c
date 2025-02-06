/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:26:37 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/21 12:20:48 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(int len, int *stack)
{
	while(--len) 
	{
		if (*stack  < *(stack + 1))
			stack++;
		else
			return (0);
	}
	return (1);
}
