/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:06:09 by paprzyby          #+#    #+#             */
/*   Updated: 2024/08/13 17:12:58 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *message, t_list *philo)
{
	if (philo)
		free(philo);
	printf("Error\n");
	printf("%s", message);
	exit(1);
}

int	main(int ac, char **av)
{
	t_list	*philo;
	int		i;

	philo = malloc(sizeof(t_list));
	i = 1;
	if (ac != 5 && ac != 6)
		return (error("Wrong number of arguments passed\n", philo));
	while (i < ac)
	{
		check_and_init(av[i], i, philo);
		i++;
	}
	free(philo);
	return(0);
}

//if (pthread_create(&t1, NULL, &philo, NULL) != 0)
//		error;
//if (pthread_join(t1, NULL) != 0)
//		error;
//child process is always 0
//main process is always different than 0
//fork returns -1 for errors
//if you call fork() 2 times, you will get 4 processes