/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:06:09 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/09 14:34:29 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 5 && ac != 6)
		return (ft_putstr_fd("Error: Wrong number of arguments passed\n", 2), 1);
	if (arg_check(ac, av))
		return (1);
	if (!(data = struct_init(ac, av)))
		return (1);
	if (philos_forks_init(data))
		return (1);
	// printf("time_to_die: %d\n", data->time_to_die);
	// printf("time_to_eat: %d\n", data->time_to_eat);
	// printf("time_to_sleep: %d\n", data->time_to_sleep);
	// printf("num_of_times: %d\n", data->num_of_times);
	// printf("philo_count: %d\n", data->philo_count);
	// printf("forks_count: %d\n", data->forks_count);
	cleanup(data);
	return (0);
}
