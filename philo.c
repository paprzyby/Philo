/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:26:56 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/13 14:01:28 by paprzyby         ###   ########.fr       */
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

int	check_dead_flag(t_philo *philos)
{
	t_data	*data;

	data = philos->data;
	pthread_mutex_lock(&data->dead_lock);
	if (philos->dead_flag == true)
		return (pthread_mutex_unlock(&data->dead_lock), 1);
	pthread_mutex_unlock(&data->dead_lock);
	return (0);
}

void	*philo_function(void *arg)
{
	t_philo *philos = (t_philo *)arg;
	t_data	*data;

	data = philos->data;
	if (philos->id % 2)
		usleep(100000);
	pthread_mutex_lock(&data->write_lock);
	printf("(timestamp_in_ms) %d is thinking\n", philos->id);
	pthread_mutex_unlock(&data->write_lock);
	if (check_dead_flag(philos))
		return (arg);
	return (arg);
}

int	philo(t_data *data)
{
	pthread_t	checker;
	t_philo		*philos;
	int			i;

	if (pthread_create(&checker, NULL, checker_function, data) != 0)
		return (1);
	i = 0;
	philos = data->philos;
	while (i < data->philo_count)
	{
		if (pthread_create(&data->philos[i].philo, NULL, philo_function, &philos[i]) != 0)
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
