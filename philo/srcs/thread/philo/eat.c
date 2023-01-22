/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 01:39:19 by kyoda             #+#    #+#             */
/*   Updated: 2023/01/22 11:42:30 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat_stamp(t_data *data, t_philo *philo)
{
	size_t	time;

	time = get_time();
	pthread_mutex_lock(&data->last_eat_mutex[philo->index]);
	data->last_eat_time[philo->index] = time;
	pthread_mutex_unlock(&data->last_eat_mutex[philo->index]);
	while (get_time() - time < philo->data->time_to_eat)
		usleep(100);
	return (0);
}

static void	end_of_eating(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->last_eat_mutex[philo->index]);
	data->end[philo->index] = true;
	pthread_mutex_unlock(&data->last_eat_mutex[philo->index]);
}

int	ft_eat(t_philo *philo, t_data *data)
{
	if (message(EAT, philo))
		return (ft_mutex_unlock(&philo->fork1, philo->fork2, 2));
	if (data->is_meals)
	{
		if (data->number_of_meals[philo->index])
		{
			data->number_of_meals[philo->index]--;
			if (!data->number_of_meals[philo->index])
				end_of_eating(data, philo);
		}
	}
	eat_stamp(data, philo);
	ft_mutex_unlock(&philo->fork1, philo->fork2, 2);
	return (0);
}
