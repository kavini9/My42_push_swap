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

int		get_len_if_arg_valid(char **inp);
void	free_arr(char ***arr);
void    arg_parse(int index, char **inp, int *stack);
void    stack_normalize(int len, int *inp, t_stack *stack);
void    exit_push_swap(char *param, char ***arr, int **stack);
int 		is_sorted(int len, int *stack);
void radix_sort(int len, t_stack *stack);

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
