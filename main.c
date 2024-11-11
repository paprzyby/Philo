/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:06:09 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/11 15:14:59 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

	if (ac != 5 && ac != 6)
		return (ft_putstr_fd("Error: Wrong number of arguments passed\n", 2), 1);
	i = 1;
	while (ac > i)
	{
		if (!ft_isdigit(av[i]))
			return (ft_putstr_fd("Error: Positive numeric arguments required\n", 2), 1);
		if (ft_atol(av[i]) > INT_MAX)
			return (ft_putstr_fd("Error: Numbers are too big\n", 2), 1);
		i++;
	}
	if (!(data = struct_init(ac, av)))
		return (1);
	cleanup(data);
	return (0);
}
