/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:02:05 by kyoda             #+#    #+#             */
/*   Updated: 2023/01/07 15:49:19 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	get_deth_flag(t_philo *philo)
{
	bool	ans;

	pthread_mutex_lock(&philo->is_death);
	ans = philo->is_dead;
	pthread_mutex_unlock(&philo->is_death);
	return (ans);
}

int	ft_sleep(t_philo *philo)
{
	size_t	sleep_time;

	if (get_deth_flag(philo))
		return (1);
	sleep_time = get_time();
	action_message(SLEEP, philo);
	while (get_time() - sleep_time < philo->data->time_to_sleep)
		usleep(1000);
	return (0);
}

int	ft_eat(t_philo *philo)
{
	size_t	eat_time;

	if (get_deth_flag(philo))
	{
		pthread_mutex_unlock(&philo->fork1);
		pthread_mutex_unlock(philo->fork2);
		return (1);
	}
	action_message(EAT, philo);
	eat_time = get_time();
	while (get_time() - eat_time < philo->data->time_to_eat)
		usleep(1000);
	about_last_eat_time(philo, 0);
	pthread_mutex_unlock(&philo->fork1);
	pthread_mutex_unlock(philo->fork2);
	return (0);
}

int	ft_fork(t_philo *philo)
{
	if (get_deth_flag(philo))
		return (1);
	pthread_mutex_lock(&philo->fork1);
	action_message(FORK, philo);
	pthread_mutex_lock(philo->fork2);
	action_message(FORK, philo);
	return (0);
}

int	ft_think(t_philo *philo)
{
	if (get_deth_flag(philo))
		return (1);
	action_message(THINK, philo);
	return (0);
}
