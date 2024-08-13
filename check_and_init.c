/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:48:11 by paprzyby          #+#    #+#             */
/*   Updated: 2024/08/13 17:24:09 by paprzyby         ###   ########.fr       */
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
	long result;
	int sign;

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

void	check_and_init(char *str, int i, t_list *philo)
{
	long	num;

	if (!is_digit(str))
		error("Arguments should only contain numbers\n", philo);
	num = ft_atol(str);
	if (num > INT_MAX)
		error("Arguments have to fit in a integer\n", philo);
	if (i == 1)
	{
		if (num < 1)
			error("Too few philosophers passed as a argument\n", philo);
		philo->philo_count = num;
		philo->forks_count = num;
	}
	else if (i == 2)
		philo->time_to_die = num;
	else if (i == 3)
		philo->time_to_eat = num;
	else if (i == 4)
	{
		philo->time_to_sleep = num;
		philo->num_of_times = 0;
	}
	else if (i == 5)
		philo->num_of_times = num;
}
