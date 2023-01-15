/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:26:11 by keys              #+#    #+#             */
/*   Updated: 2023/01/13 04:00:11 by kyoda            ###   ########.fr       */
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
		usleep(10000);
		break ;
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
