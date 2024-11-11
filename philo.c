/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:26:56 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/11 16:03:12 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*checker_function(void *arg)
{
	t_data *data = (t_data *)arg;
	(void)data;
	printf("checker function\n");
	return (0);
}

void	*philo_function(void *arg)
{
	t_data *data = (t_data *)arg;
	(void)data;
	printf("philo function\n");
	return (0);
}

int	philo(t_data *data)
{
	pthread_t	checker;
	int			i;

	if (pthread_create(&checker, NULL, checker_function, data) != 0)
		return (1);
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_create(&data->philos[i].philo, NULL, philo_function, data) != 0)
			return (1);
		i++;
	}
	if (pthread_join(checker, NULL) != 0)
		return (1);
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_join(data->philos[i].philo, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
