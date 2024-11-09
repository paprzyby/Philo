/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:02:54 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/09 17:47:33 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(PHILO_H)
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* ----------  mutexes ---------- */

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				id;
}					t_fork;

/* ----------  threads ---------- */

typedef struct s_philo
{
	pthread_t		philo;
	int				id;
	int				meals;
	long			last_meal;
	bool			full;
	bool			dead_flag;
	t_fork			*left_fork;
	t_fork			*right_fork;
}					t_philo;

/* ----------  program data ---------- */

typedef struct s_data
{
	int				philo_count;
	int				forks_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times;
	t_philo			*philos;
	t_fork			*forks;
}					t_data;

void				ft_putstr_fd(char *s, int fd);

int					data_init(int ac, char **av, t_data *data);
void				philos_forks_init(t_data *data);

bool				is_digit(char *str);
long				ft_atol(char *str);
int					arg_check(int ac, char **av);
t_data				*struct_init(int ac, char **av);
void				cleanup(t_data *data);
void				philos_init(t_data *data);
void				forks_init(t_data *data);

#endif
