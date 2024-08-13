/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:02:54 by paprzyby          #+#    #+#             */
/*   Updated: 2024/08/13 14:47:09 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(PHILO_H)
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct	s_list
{
	int	philo_count;
	int	forks_count;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_times;
}				t_list;

int		error(char *message);
bool	is_digit(char *str);
int		ft_atoi(char *str);
void	check_and_init(char *str, int i, t_list *philo);

#endif
