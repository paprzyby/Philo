/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:17:22 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/15 18:13:24 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	death_check(t_data *data, t_philo *philos, long time_to_die)
{
	pthread_mutex_lock(&data->meal_lock);
	if (get_timestamp() - philos->last_meal >= time_to_die && !philos->eating)
		return (pthread_mutex_unlock(&data->meal_lock), 1);
	pthread_mutex_unlock(&data->meal_lock);
	return (0);
}

void	check_the_flags(t_data *data, int i, int finished_eating)
{
	while (i < data->philo_count)
	{
		if (death_check(data, &data->philos[i], data->time_to_die))
		{
			print_message(data->philos, i + 1, "died");
			pthread_mutex_lock(&data->dead_lock);
			data->philo_died = true;
			pthread_mutex_unlock(&data->dead_lock);
			return ;
		}
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
	while (1)
	{
		i = 0;
		finished_eating = 0;
		check_the_flags(data, i, finished_eating);
		if (data->all_ate == true || data->philo_died == true)
			break ;
	}
	return (arg);
}
