#include "../includes/push_swap.h"

static int	is_empty(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (!((*str >= 9 && *str <= 13) || *str == ' '))
			return (0);
		str++;
	}
	return (1);
}

static int	is_valid_multi(char *inp)
{
	printf("inp in multi: %s\n", inp);
	while (*inp)
	{
		while (((*inp >= 9 && *inp <= 13) || *inp == ' ') && *(inp + 1))
			inp++;
		if (*inp == '+' || *inp == '-')
		{
			if (*(inp + 1) && ft_isdigit(*(inp + 1)))
				inp++;
			else
				return(0);
		}
		while (*inp && !((*inp >= 9 && *inp <= 13) || *inp == ' '))
		{
			if (!ft_isdigit(*inp))
				return (0);
			printf("%c\n", *inp);
			inp++;
		}
		if (((*inp >= 9 && *inp <= 13) || *inp == ' ') && !*(inp + 1))
			inp++;
	}
	return (1);
}

static int	is_valid_single(char *inp)
{
	while (((*inp >= 9 && *inp <= 13) || *inp == ' ') && *(inp + 1))
		inp++;
	if ((*inp == '+' || *inp == '-') && *(inp + 1))
		inp++;
	while (*inp)
	{
		if (!ft_isdigit(*inp))
			return (0);
		inp++;
	}
	return (1);
}

int	is_valid_arg(char **inp)
{
	while (*inp)
	{
		printf("inp in main loop: %s\n", *inp);
		if (is_empty(*inp))
			return (0);
		if (!is_valid_single(*inp))
		{
			printf("not a single inp\n");
			if (!is_valid_multi(*inp))
			{
				printf("not a multi inp\n");
				return (0);
			}
		}
		inp++;
	}
	return (1);
}
