/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:26:44 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/21 11:35:45 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include <stddef.h>
# include <stdio.h>

typedef struct s_node
{
	int			num;
	int			index;
	struct s_node	*next;
}	t_node;

int		is_valid_arg(char **inp);
void	free_arr(char ***arr);
int		arg_parse(char **inp, t_node **stack);
void	exit_push_swap(t_node **stack);
t_node	*ft_stacknew(int num, int index);
void	ft_stackadd_back(t_node **stack, t_node *new);
t_node	*ft_stacklast(t_node *stack);
int 		is_sorted(t_node *stack);
//int	ft_stacksize(t_node *stack);

#endif
