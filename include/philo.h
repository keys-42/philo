/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:12:03 by keys              #+#    #+#             */
/*   Updated: 2023/01/07 15:57:30 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# define FORK "%lu %d has taken a fork\n"
# define EAT "%lu %d is eating\n"
# define SLEEP "%lu %d is sleeping\n"
# define THINK "%lu %d is thinking\n"
# define DIE "%lu %d died\n"

typedef struct s_philo
{
	int				id;
	struct s_data	*data;
	bool			is_dead;
	pthread_mutex_t	fork1;
	pthread_mutex_t	*fork2;
	pthread_mutex_t	is_death;
}					t_philo;

typedef struct s_data
{
	bool			is_dead;
	size_t			philosophers_num;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start;
	size_t			last_eat_time[200];
	t_philo			philo[200];
	pthread_t		thread[200];
	size_t			number_of_meals[200];
	pthread_mutex_t	death_check;
	pthread_mutex_t	print;
	pthread_mutex_t	last_eat_mutex[200];
}					t_data;

int					ft_checks(t_data *data, int argc, char **argv);
int					ft_make_data(t_data *data, int argc, char **argv);
int					ft_make_mutex(t_data *data);
int					ft_make_thread(t_data *data);
int					ft_error_print(char *mes);
long				ft_atol(const char *nptr);
int					ft_isdigit(int c);
int					ft_isspace(int c);
void				*philosophers(void *arg);
int					ft_think(t_philo *philo);
int					ft_fork(t_philo *philo);
int					ft_eat(t_philo *philo);
int					ft_sleep(t_philo *philo);
size_t				about_last_eat_time(t_philo *philo, int flag);
void				*death_watch(void *arg);
size_t				get_time(void);
bool				get_deth_flag(t_philo *philo);
void				action_message(char *mes, t_philo *philo);
bool	someone_dead(t_data *data);

#endif
