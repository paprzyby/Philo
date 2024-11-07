/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:09:03 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/07 17:44:43 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = NULL;
	while (i < data->philo_count)
	{
		philo->id = i + 1;
		philo->meals = 0;
		philo->full = false;
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
			return (printf("Too few philosophers passed as a argument\n"), 1);
		else if (i == 1 && ft_atol(av[i]) > 200)
			return (printf("Too much philosophers passed as a argument\n"), 1);
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
	return (0);
}

t_data	*init(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (printf("Error while allocating memory\n"), NULL);
	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
	{
		free(data);
		return (printf("Error while allocating memory\n"), NULL);
	}
	data->forks = malloc(sizeof(t_fork) * data->philo_count);
	if (!data->forks)
	{
		free(data->philos);
		free(data);
		return (printf("Error while allocating memory\n"), NULL);
	}
	if (data_init(ac, av, data))
	{
		free(data->philos);
		free(data->forks);
		return (free(data), NULL);
	}
	// philo_init(data);
	return (data);
}
