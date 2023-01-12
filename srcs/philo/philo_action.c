/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:02:05 by kyoda             #+#    #+#             */
/*   Updated: 2023/01/12 23:12:52 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_sleep(t_philo *philo)
{
	size_t	start_time;

	if (action_message(SLEEP, philo))
		return (1);
	start_time = get_time();
	while (get_time() - start_time < philo->data->time_to_sleep)
		usleep(10);
	return (0);
}

static void	ft_eat_utils(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->meals);
	philo->data->b_meals[philo->id - 1] = true;
	pthread_mutex_unlock(&philo->data->meals);
}

int	ft_eat(t_philo *philo)
{
	size_t	eat_time;

	if (action_message(EAT, philo))
	{
		pthread_mutex_unlock(&philo->fork1);
		pthread_mutex_unlock(philo->fork2);
		return (1);
	}
	eat_time = get_time();
	while (get_time() - eat_time < philo->data->time_to_eat)
		usleep(10);
	pthread_mutex_unlock(&philo->fork1);
	pthread_mutex_unlock(philo->fork2);
	about_last_eat_time(philo, 0);
	if (philo->data->is_meals)
	{
		if (philo->data->number_of_meals[philo->id - 1])
		{
			philo->data->number_of_meals[philo->id - 1]--;
			if (!philo->data->number_of_meals[philo->id - 1])
				ft_eat_utils(philo);
		}
	}
	return (0);
}

int	ft_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork1);
	if (action_message(FORK, philo))
		return (1);
	pthread_mutex_lock(philo->fork2);
	if (action_message(FORK, philo))
	{
		pthread_mutex_unlock(&philo->fork1);
		return (1);
	}
	return (0);
}

int	ft_think(t_philo *philo)
{
	return (action_message(THINK, philo));
}
