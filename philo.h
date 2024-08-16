/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:02:54 by paprzyby          #+#    #+#             */
/*   Updated: 2024/08/16 14:00:18 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(PHILO_H)
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct	s_list
{
	int	philo_count;
	int	forks_count;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_times;
}				t_list;

int		error(char *message, t_list *list);
bool	is_digit(char *str);
long	ft_atol(char *str);
void	check_and_init(char *str, int i, t_list *list);

#endif
