/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:17:22 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/13 15:57:40 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	check_the_flags(t_data *data, int i, int finished_eating)
{
	while (i < data->philo_count)
	{
		pthread_mutex_lock(&data->dead_lock);
		if (data->philos[i].dead_flag == true)
		{
			pthread_mutex_lock(&data->write_lock);
			printf("%ld %d died\n", get_timestamp(), i);
			data->philo_died = true;
			pthread_mutex_unlock(&data->write_lock);
			pthread_mutex_unlock(&data->dead_lock);
			return ;
		}
		pthread_mutex_unlock(&data->dead_lock);
		pthread_mutex_lock(&data->meal_lock);
		if (data->philos[i].full == true)
			finished_eating++;
		pthread_mutex_unlock(&data->meal_lock);
		i++;
	}
	if (finished_eating == data->philo_count)
	{
		pthread_mutex_lock(&data->meal_lock);
		data->all_ate = true;
		pthread_mutex_unlock(&data->meal_lock);
	}
}

void	*checker_function(void *arg)
{
	t_data	*data;
	int		i;
	int		finished_eating;

	data = (t_data *)arg;
	i = 0;
	finished_eating = 0;
	while (1)
	{
		check_the_flags(data, i, finished_eating);
		if (data->all_ate == true || data->philo_died == true)
			break ;
	}
	return (arg);
}
