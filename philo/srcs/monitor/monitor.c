/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:19:42 by keys              #+#    #+#             */
/*   Updated: 2023/01/12 23:11:48 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	moniter_time(void)
{
	struct timeval	time_result;
	size_t			time;
	int				flag;

	flag = 0;
	flag = gettimeofday(&time_result, NULL);
	if (flag == -1)
		return (-1);
	time = time_result.tv_sec * 1000 + time_result.tv_usec / 1000;
	return (time);
}

static bool	is_alive(t_philo *philo)
{
	size_t	now;
	size_t	last;

	now = moniter_time();
	last = about_last_eat_time(philo, 1);
	if ((now - last) > philo->data->time_to_die)
		return (someone_dead(philo));
	return (false);
}

static bool	thread_stop(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philosophers_num)
	{
		pthread_mutex_lock(&data->philo[i].is_death);
		i++;
	}
	i = 0;
	while (i < data->philosophers_num)
	{
		data->philo[i].is_dead = true;
		pthread_mutex_unlock(&data->philo[i].is_death);
		i++;
	}
	return (true);
}

static bool	can_eat(t_data *data)
{
	bool	which;
	size_t	i;

	which = true;
	i = 0;
	pthread_mutex_lock(&data->meals);
	while (i < data->philosophers_num)
	{
		if (!data->b_meals[i])
		{
			which = false;
			break ;
		}
		i++;
	}
	pthread_mutex_unlock(&data->meals);
	if (which)
		return (thread_stop(data));
	return (which);
}

void	*death_watch(void *arg)
{
	t_data	*data;
	size_t	i;
	size_t	j;

	data = (t_data *)arg;
	j = data->philosophers_num;
	while (42)
	{
		i = 0;
		while (i < j)
		{
			if (is_alive(&data->philo[i]))
				return (NULL);
			i++;
		}
		if (can_eat(data))
			return (NULL);
	}
	return (NULL);
}
