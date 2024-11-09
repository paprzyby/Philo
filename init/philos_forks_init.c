/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_forks_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:56:30 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/09 13:03:06 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

int	philos_forks_init(t_data *data)
{
	philo_init(data);
	return (0);
}
