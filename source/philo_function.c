/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:17:18 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/16 12:50:40 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	process_duration(long time, t_data *data)
{
	long long	i;

	i = get_timestamp();
	while (data->philo_died == false && data->all_ate == false)
	{
		if (get_timestamp() - i >= time)
			break ;
		usleep(100);
	}
}

void	eating(t_data *data, t_philo *philos)
{
	pthread_mutex_lock(philos->right_fork);
	print_message(philos, philos->id, "has taken a fork");
	pthread_mutex_lock(philos->left_fork);
	print_message(philos, philos->id, "has taken a fork");
	philos->eating = true;
	print_message(philos, philos->id, "is eating");
	pthread_mutex_lock(&data->meal_lock);
	philos->meals_eaten++;
	philos->last_meal = get_timestamp();
	pthread_mutex_unlock(&data->meal_lock);
	process_duration(data->time_to_eat, data);
	philos->eating = false;
	pthread_mutex_unlock(philos->left_fork);
	pthread_mutex_unlock(philos->right_fork);
}

void	*philo_function(void *arg)
{
	t_philo	*philos;
	t_data	*data;

	philos = (t_philo *)arg;
	data = philos->data;
	if (philos->id % 2)
		usleep(1000);
	while (data->philo_died == false && data->all_ate == false)
	{
		eating(data, philos);
		if (philos->meals_eaten == data->time_of_eats)
		{
			philos->full = true;
			break;
		}
		print_message(philos, philos->id, "is sleeping");
		process_duration(data->time_to_sleep, data);
		print_message(philos, philos->id, "is thinking");
	}
	pthread_mutex_unlock(&data->dead_lock);
	return (arg);
}

// if (data->philo_count == 1)????