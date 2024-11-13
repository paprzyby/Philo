/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:09:03 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/13 13:53:21 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
}

void	philos_init(t_data *data, t_philo *philos, pthread_mutex_t *forks)
{
	int		i;

	i = 0;
	while (i < data->philo_count)
	{
		philos[i].id = i + 1;
		philos[i].meals = 0;
		philos[i].last_meal = 0;
		philos[i].full = false;
		philos[i].dead_flag = false;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % data->philo_count];
		philos[i].data = data;
		i++;
	}
}

int	data_init(int ac, char **av, t_data *data)
{
	int	i;

	i = 1;
	data->num_of_times = 0;
	while (ac > i)
	{
		if (i == 1 && ft_atol(av[i]) < 1)
			return (ft_putstr_fd("Too few philosophers passed as a argument\n", 2), 1);
		else if (i == 1 && ft_atol(av[i]) > 200)
			return (ft_putstr_fd("Too much philosophers passed as a argument\n", 2), 1);
		else if (i == 2)
			data->time_to_die = ft_atol(av[i]);
		else if (i == 3)
			data->time_to_eat = ft_atol(av[i]);
		else if (i == 4)
			data->time_to_sleep = ft_atol(av[i]);
		else if (i == 5)
			data->num_of_times = ft_atol(av[i]);
		else
			data->philo_count = ft_atol(av[i]);
		i++;
	}
	return (0);
}

t_data	*struct_init(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (ft_putstr_fd("Error while allocating memory\n", 2), NULL);
	if (data_init(ac, av, data))
		return (free(data), NULL);
	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
	{
		free(data);
		return (ft_putstr_fd("Error while allocating memory\n", 2), NULL);
	}
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
	{
		free(data->philos);
		return (free(data), NULL);
	}
	forks_init(data);
	philos_init(data, data->philos, data->forks);
	return (data);
}
