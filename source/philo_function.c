/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:17:18 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/13 15:07:13 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
