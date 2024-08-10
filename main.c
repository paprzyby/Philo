/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:06:09 by paprzyby          #+#    #+#             */
/*   Updated: 2024/08/10 17:48:15 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo()
{
	printf("Philosophers\n");
	sleep(3);
	printf("Ending thread\n");
	return (0);
}

int	main()
{
	pthread_t	t1;
	int			id;

	id = fork();
	printf("ID: %d\n", id);
	if (pthread_create(&t1, NULL, &philo, NULL) != 0)
	{
		printf("Error, while creating the first thread\n");
		return (1);
	}
	if (pthread_join(t1, NULL) != 0)
	{
		printf("Error, while creating the first thread\n");
		return (1);
	}
	return (0);
}

//if (pthread_create(&t1, NULL, &philo, NULL) != 0)
//		error;
//if (pthread_join(t1, NULL) != 0)
//		error;