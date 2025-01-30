/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:26:44 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/30 19:30:54 by wweerasi         ###   ########.fr       */
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
/*
typedef struct s_pos
{
	t_node	top_a;
	t_node	bottom_a;
	t_node	top_b;
	t_node	bottom_b;
}
*/

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
}	t_stack;


int		is_valid_arg(char **inp);
void	free_arr(char ***arr);
int		arg_parse(char **inp, t_node **stack);
void    stack_normalize(int size, t_node *inp, t_stack *stack);
void	exit_push_swap(char *param, t_node **stack);
t_node	*ps_stacknew(int num, int index);
void	ps_stackadd_back(t_node **stack, t_node *new);
t_node	*ps_stacklast(t_node *stack);
void     ps_lstclear(t_node **stack);
int 		is_sorted(t_node *stack);
void radix_sort(t_stack *stack);

#endif
