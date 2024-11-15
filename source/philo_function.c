/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:17:18 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/15 11:17:32 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	process_duration(long time, t_data *data)
{
	long long i;

	i = get_timestamp();
	while (data->philo_died == false)
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
	t_philo *philos = (t_philo *)arg;
	t_data	*data;

	data = philos->data;
	if (philos->id % 2)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(&data->dead_lock);
		if (data->philo_died == true || data->all_ate == true)
			break ;
		pthread_mutex_unlock(&data->dead_lock);
		eating(data, philos);
		print_message(philos, philos->id, "is sleeping");
		process_duration(data->time_to_sleep, data);
		print_message(philos, philos->id, "is thinking");
	}
	pthread_mutex_unlock(&data->dead_lock);
	return (arg);
}

//if (data->philo_count == 1)????