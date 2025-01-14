#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	if (ac <= 2)
		return(EXIT_SUCCESS);
	if (!is_valid_arg(av + 1))
		return (printf("error()\n"));
	printf("success");
	return(0);
}



