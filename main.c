/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:06:09 by paprzyby          #+#    #+#             */
/*   Updated: 2024/08/10 17:37:26 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo()
{
	printf("Philosophers\n");
	return (0);
}

int	main()
{
	pthread_t	t1;
	pthread_t	t2;

	pthread_create(&t1, NULL, &philo, NULL);
	pthread_create(&t2, NULL, &philo, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}
