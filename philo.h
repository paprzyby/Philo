/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:02:54 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/13 15:45:39 by paprzyby         ###   ########.fr       */
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
# include <sys/time.h>

/* ----------  threads and mutexes ---------- */

struct s_data;

typedef struct s_philo
{
	pthread_t		philo;
	int				id;
	int				meals_eaten;
	long			last_meal;
	bool			full;
	bool			dead_flag;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}					t_philo;

/* ----------  program data ---------- */

typedef struct s_data
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_of_eats;
	bool			all_ate;
	bool			philo_died;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_data;

void				ft_putstr_fd(char *s, int fd);
bool				ft_isdigit(char *str);
long				ft_atol(char *str);

void				cleanup(t_data *data);

t_data				*struct_init(int ac, char **av);
int					data_init(int ac, char **av, t_data *data);
void				philos_init(t_data *data, t_philo *philos, pthread_mutex_t *forks);
void				forks_init(t_data *data);

int					creating_threads(t_data *data);
void				*checker_function(void *arg);
void				*philo_function(void *arg);

void				check_the_flags(t_data *data, int i, int finished_eating);

#endif
