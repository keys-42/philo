/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:19:42 by keys              #+#    #+#             */
/*   Updated: 2023/01/18 22:55:33 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_alive(t_data *data, t_philo *philo)
{
	size_t	now;
	size_t	last;
	size_t	i;
	size_t	j;

	i = 0;
	j = data->philosophers_num;
	while (i < j)
	{
		pthread_mutex_lock(&data->last_eat_mutex[i]);
		last = data->last_eat_time[i];
		pthread_mutex_unlock(&data->last_eat_mutex[i]);
		now = get_time();
		if ((now - last) > philo->data->time_to_die)
			return (someone_dead(philo));
		i++;
	}
	return (false);
}

static bool	can_eat(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philosophers_num)
	{
		pthread_mutex_lock(&data->last_eat_mutex[i]);
		if (!data->end[i])
		{
			pthread_mutex_unlock(&data->last_eat_mutex[i]);
			return (false);
		}
		pthread_mutex_unlock(&data->last_eat_mutex[i]);
		i++;
	}
	return (thread_stop(data));
}

void	*death_watch(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (42)
	{
		if (is_alive(data, data->philo))
			return (NULL);
		if (can_eat(data))
			break ;
	}
	return (NULL);
}
