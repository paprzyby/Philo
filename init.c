/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:09:03 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/07 17:26:07 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_data *list)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = NULL;
	while (i < list->philo_count)
	{
		philo->id = i + 1;
		philo->meals = 0;
		philo->full = false;
		i++;
	}
}

int	data_init(int ac, char **av, t_data *list)
{
	int	i;

	i = 1;
	while (ac > i)
	{
		if (i == 1 && ft_atol(av[i]) < 1)
			return (printf("Too few philosophers passed as a argument\n"), 1);
		else if (i == 1 && ft_atol(av[i]) > 200)
			return (printf("Too much philosophers passed as a argument\n"), 1);
		else if (i == 2)
			list->time_to_die = ft_atol(av[i]);
		else if (i == 3)
			list->time_to_eat = ft_atol(av[i]);
		else if (i == 4)
		{
			list->time_to_sleep = ft_atol(av[i]);
			list->num_of_times = 0;
		}
		else if (i == 5)
			list->num_of_times = ft_atol(av[i]);
		else
			list->philo_count = ft_atol(av[i]);
		i++;
	}
	list->forks_count = list->philo_count;
	return (0);
}

t_data	*init(int ac, char **av)
{
	t_data	*list;

	list = malloc(sizeof(t_data));
	if (!list)
		return (printf("Error while allocating memory\n"), NULL);
	list->philos = malloc(sizeof(t_philo) * list->philo_count);
	if (!list->philos)
	{
		free(list);
		return (printf("Error while allocating memory\n"), NULL);
	}
	list->forks = malloc(sizeof(t_fork) * list->philo_count);
	if (!list->forks)
	{
		free(list->philos);
		free(list);
		return (printf("Error while allocating memory\n"), NULL);
	}
	if (data_init(ac, av, list))
	{
		free(list->philos);
		free(list->forks);
		free(list);
		return (NULL);
	}
	//philo_init(list);
	return (list);
}
