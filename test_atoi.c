
#include <stdio.h>
#include <stdlib.h>

long int	ft_atol(const char *str)
{
	long int			sign;
	long long int	atoi;
	long long int	buf;

	atoi = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ' )
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		buf = atoi;
		atoi = atoi * 10 + *str - '0';
		if (atoi / 10 != buf && sign == -1)
			return (0);
		else if (atoi / 10 != buf && sign == 1)
			return (-1);
		str++;
	}
	return (sign * atoi);
}

int main(int ac, char **av)
{
	int i = 1;

	while (i < ac)
	{
		printf("input string: %s\n", av[i]);
		printf("ft_atoi num : %li\n", ft_atol(av[i]));
		printf("atoi num    : %li\n", atol(av[i]));
		i++;
	}
}
