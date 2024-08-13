/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:06:09 by paprzyby          #+#    #+#             */
/*   Updated: 2024/08/13 13:43:11 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *message)
{
	printf("Error\n");
	printf("%s", message);
	return (1);
}

bool	is_digit(char *str)
{

}

int	ft_atoi(char *str)
{
	int result = 0;
	int sign = 1;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

int	check_the_arguments(char *str, int i)
{
	int	num;


	num = ft_atoi(str);
	if (i == 1)
	{

	}
}

int	main(int ac, char **av)
{
	int	i;

	(void)av;
	if (ac != 5 && ac != 6)
		return (error("Wrong number of arguments passed\n"));
	i = 1;
	while (i < ac)
		check_the_arguments(av[i++], i);
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