/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:09:03 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/09 17:55:48 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philos_init(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->philo_count)
	{
		data->philos->id = i + 1;
		data->philos->meals = 0;
		data->philos->last_meal = 0;
		data->philos->full = false;
		data->philos->dead_flag = false;
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
	data->forks_count = data->philo_count;
	philos_init(data);
	return (0);
}

t_data	*struct_init(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (ft_putstr_fd("Error while allocating memory\n", 2), NULL);
	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
	{
		free(data);
		return (ft_putstr_fd("Error while allocating memory\n", 2), NULL);
	}
	data->forks = malloc(sizeof(t_fork) * data->philo_count);
	if (!data->forks)
	{
		free(data->philos);
		free(data);
		return (ft_putstr_fd("Error while allocating memory\n", 2), NULL);
	}
	if (data_init(ac, av, data))
	{
		free(data->philos);
		free(data->forks);
		return (free(data), NULL);
	}
	return (data);
}
