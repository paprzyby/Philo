/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:48:11 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/09 14:34:11 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (false);
	}
	return (true);
}

long	ft_atol(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

int	arg_check(int ac, char **av)
{
	long	num;
	int		i;

	i = 1;
	while (ac > i)
	{
		if (!is_digit(av[i]))
			return (ft_putstr_fd("Error: Numeric arguments required\n", 2), 1);
		num = ft_atol(av[i]);
		if (num > INT_MAX)
			return (ft_putstr_fd("Error: Numbers are too big\n", 2), 1);
		i++;
	}
	return (0);
}
