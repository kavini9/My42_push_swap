/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:26:44 by wweerasi          #+#    #+#             */
/*   Updated: 2025/02/03 21:59:40 by wweerasi         ###   ########.fr       */
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

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
}	t_stack;

int		is_valid_arg(char **inp);
void	free_arr(char ***arr);
void    arg_parse(int *index, char **inp, t_node **stack);
void    stack_normalize(int size, t_node *inp, t_stack *stack);
void    exit_push_swap(char *param, char ***arr, t_node **stack);
t_node	*ps_stacknew(int num, int index);
void	ps_stackadd_back(t_node **stack, t_node *new);
t_node	*ps_stacklast(t_node *stack);
void     ps_lstclear(t_node **stack);
int 		is_sorted(t_node *stack);
void radix_sort(t_stack *stack);

//operations
void    pa(t_stack *stack);
void    pb(t_stack *stack);
void    ra(t_stack *stack);
void    rb(t_stack *stack);
void    rr(t_stack *stack);
void    rra(t_stack *stack);
void    rra(t_stack *stack);
void    rrr(t_stack *stack);

#endif
