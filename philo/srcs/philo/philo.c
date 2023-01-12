/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:26:11 by keys              #+#    #+#             */
/*   Updated: 2023/01/07 20:03:21 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	one_philo(t_philo *philo)
{
	bool	ans;

	pthread_mutex_lock(&philo->fork1);
	if (action_message(FORK, philo))
		return ;
	while (42)
	{
		pthread_mutex_lock(&philo->is_death);
		ans = philo->is_dead;
		pthread_mutex_unlock(&philo->is_death);
		if (ans)
		{
			pthread_mutex_unlock(&philo->fork1);
			return ;
		}
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
		if (ft_eat(philo))
			break ;
		if (ft_sleep(philo))
			break ;
		if (ft_think(philo))
			break ;
	}
	return (NULL);
}
