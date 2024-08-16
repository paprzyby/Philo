/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:06:09 by paprzyby          #+#    #+#             */
/*   Updated: 2024/08/16 14:00:47 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *message, t_list *list)
{
	if (list)
		free(list);
	printf("Error\n");
	printf("%s", message);
	exit(1);
}

int	main(int ac, char **av)
{
	t_list	*list;
	int		i;

	list = malloc(sizeof(t_list));
	i = 1;
	if (ac != 5 && ac != 6)
		return (error("Wrong number of arguments passed\n", list));
	while (i < ac)
	{
		check_and_init(av[i], i, list);
		i++;
	}
	free(list);
	return(0);
}
