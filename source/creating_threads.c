/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:26:56 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/15 18:22:18 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	creating_threads(t_data *data)
{
	pthread_t	checker;
	t_philo		*philos;
	int			i;

	if (pthread_create(&checker, NULL, checker_function, data) != 0)
		return (1);
	i = 0;
	philos = data->philos;
	while (i < data->philo_count)
	{
		if (pthread_create(&data->philos[i].philo, NULL, philo_function,
				&philos[i]) != 0)
			return (1);
		i++;
	}
	if (pthread_join(checker, NULL) != 0)
		return (1);
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_join(data->philos[i].philo, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
