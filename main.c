/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:06:09 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/07 17:25:54 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*list;

	if (ac != 5 && ac != 6)
		return (printf("Error: Wrong number of arguments passed\n"), 1);
	if (arg_check(ac, av))
		return (1);
	if (!(list = init(ac, av)))
		return (1);
	//printf("time_to_die: %d\n", list->time_to_die);
	//printf("time_to_eat: %d\n", list->time_to_eat);
	//printf("time_to_sleep: %d\n", list->time_to_sleep);
	//printf("num_of_times: %d\n", list->num_of_times);
	//printf("philo_count: %d\n", list->philo_count);
	//printf("forks_count: %d\n", list->forks_count);
	//cleanup
	return(0);
}
