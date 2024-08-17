/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:09:03 by paprzyby          #+#    #+#             */
/*   Updated: 2024/08/17 09:36:25 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_data *list)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < list->philo_count)
	{
		philo->id = i + 1;
		philo->meals = 0;
		philo->full = false;
		i++;
	}
}

void	init(t_data *list)
{
	list->philos = malloc(sizeof(t_philo) * list->philo_count);
	if (!list->philos)
		error("while allocating memory", list);
	list->forks = malloc(sizeof(t_fork) * list->philo_count);
	if (!list->forks)
	{
		free(list->philos);
		error("while allocating memory", list);
	}
	philo_init(list);
}

//free the list->philos properly