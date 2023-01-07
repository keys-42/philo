/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_deth.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 00:06:40 by keys              #+#    #+#             */
/*   Updated: 2023/01/07 19:36:49 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	about_last_eat_time(t_philo *philo, int flag)
{
	size_t	ans;

	pthread_mutex_lock(&philo->data->last_eat_mutex[philo->id - 1]);
	if (flag == 0)
	{
		philo->data->last_eat_time[philo->id - 1] = get_time();
	}
	ans = philo->data->last_eat_time[philo->id - 1];
	pthread_mutex_unlock(&philo->data->last_eat_mutex[philo->id - 1]);
	return (ans);
}

void	set_flag(t_philo *philo)
{
	philo->is_dead = true;
	pthread_mutex_unlock(&philo->is_death);
}

bool	someone_dead(t_philo *philo)
{
	size_t	i;

	i = 0;
	while (i < philo->data->philosophers_num)
	{
		pthread_mutex_lock(&philo->data->philo[i].is_death);
		i++;
	}
	i = 0;
	while (i < philo->data->philosophers_num)
	{
		set_flag(&philo->data->philo[i]);
		i++;
	}
	pthread_mutex_lock(&philo->data->print);
	printf(DIE, get_time() - philo->data->start, philo->id);
	pthread_mutex_unlock(&philo->data->print);
	return (true);
}
