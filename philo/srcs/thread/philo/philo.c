/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:26:11 by keys              #+#    #+#             */
/*   Updated: 2023/01/22 11:53:21 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	one_philo(t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(&philo->fork1);
	time = get_time() - philo->data->start;
	pthread_mutex_lock(&philo->data->print);
	printf(FORK, time, philo->id);
	pthread_mutex_unlock(&philo->data->print);
	while (42)
	{
		pthread_mutex_lock(&philo->data->stop[philo->index]);
		if (philo->finish)
		{
			pthread_mutex_unlock(&philo->data->stop[philo->index]);
			return ;
		}
		pthread_mutex_unlock(&philo->data->stop[philo->index]);
	}
}

void	*philosophers(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->philosophers_num == 1)
	{
		one_philo(philo);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(100);
	while (42)
	{
		if (ft_fork(philo))
			break ;
		if (ft_eat(philo, philo->data))
			break ;
		if (ft_sleep(philo))
			break ;
		if (ft_think(philo))
			break ;
	}
	return (NULL);
}
