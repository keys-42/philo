/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_deth.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 00:06:40 by keys              #+#    #+#             */
/*   Updated: 2023/01/07 15:59:40 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	about_last_eat_time(t_philo *philo, int flag)
{
	size_t	ans;

	pthread_mutex_lock(&philo->data->last_eat_mutex[philo->id]);
	if (flag == 0)
	{
		philo->data->last_eat_time[philo->id] = get_time();
	}
	ans = philo->data->last_eat_time[philo->id];
	pthread_mutex_unlock(&philo->data->last_eat_mutex[philo->id]);
	return (ans);
}

void	set_flag(t_philo *philo)
{
	pthread_mutex_lock(&philo->is_death);
	philo->is_dead = true;
	pthread_mutex_unlock(&philo->is_death);
}

void	dying_message(char *mes, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	printf(mes, get_time() - philo->data->start, philo->id);
	usleep(5000);
	pthread_mutex_unlock(&philo->data->print);
}

bool	someone_dead(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philosophers_num)
	{
		set_flag(&data->philo[i]);
		i++;
	}
	data->is_dead = true;
	dying_message(DIE, data->philo);
	return (true);
}
