/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:02:54 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/07 17:23:11 by paprzyby         ###   ########.fr       */
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

typedef struct	s_fork
{
	pthread_mutex_t	fork;
	int				id;
}				t_fork;

typedef struct	s_philo
{
	pthread_t	philo;
	int			id;
	long		meals;
	bool		full;
	long		last_meal;
	t_fork		*left_fork;
	t_fork		*right_fork;
}				t_philo;

typedef struct	s_data
{
	int		philo_count;
	int		forks_count;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_of_times;
	t_philo	*philos;
	t_fork	*forks;
}				t_data;

bool	is_digit(char *str);
long	ft_atol(char *str);
int		arg_check(int ac, char **av);
t_data	*init(int ac, char **av);
void	philo_init(t_data *list);
int		data_init(int ac, char **av, t_data *list);

#endif
