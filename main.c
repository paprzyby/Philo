/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:06:09 by paprzyby          #+#    #+#             */
/*   Updated: 2024/08/10 16:10:39 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo(char *str)
{
	if (*str == 'c')
		printf("cwel");
	else if (*str == 'p')
		printf("pedal");
}

int	main(int ac, char **av)
{
	if (ac == 2)
		philo(av[1]);
	printf("\n");
	return (0);
}
