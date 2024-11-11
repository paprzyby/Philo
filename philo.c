/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:26:56 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/11 15:41:11 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*checker_function(void *arg)
{
	t_data *data = (t_data *)arg;
	(void)data;
	printf("checker function\n");
	return (0);
}

int	philo(t_data *data)
{
	pthread_t	checker;

	if (pthread_create(&checker, NULL, checker_function, data) != 0)
		return (1);
	if (pthread_join(checker, NULL) != 0)
		return (1);
	return (0);
}
