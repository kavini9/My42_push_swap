#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include <stddef.h>
# include <stdio.h>

typedef struct s_node
{
	int		num;
	int		rank;
	struct s_node	*next;
}	t_node;

int	is_valid_arg(char **inp);
void	free_arr(char ***arr);
t_node	*arg_parse(char **inp);
void	exit_push_swap(t_node **stack_a);
t_node	*ft_stacknew(int num, int rank);
void	ft_stackadd_back(t_node **stack, t_node *new);
t_node	*ft_stacklast(t_node *stack);

#endif
