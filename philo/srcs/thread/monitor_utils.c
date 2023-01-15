/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 04:15:12 by kyoda             #+#    #+#             */
/*   Updated: 2023/01/13 04:24:24 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	thread_stop(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philosophers_num)
	{
		pthread_mutex_lock(&data->stop[i]);
		i++;
	}
	i = 0;
	while (i < data->philosophers_num)
	{
		data->philo[i].finish = true;
		pthread_mutex_unlock(&data->stop[i]);
		i++;
	}
	return (true);
}

bool	someone_dead(t_philo *philo)
{
	thread_stop(philo->data);
	pthread_mutex_lock(&philo->data->print);
	printf(DIE, get_time() - philo->data->start, philo->id);
	pthread_mutex_unlock(&philo->data->print);
	return (true);
}