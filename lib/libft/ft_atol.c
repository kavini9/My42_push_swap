/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:14:22 by wweerasi          #+#    #+#             */
/*   Updated: 2025/01/18 14:51:24 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_atol(const char *str)
{
	long int		sign;
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
