/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:30:11 by keys              #+#    #+#             */
/*   Updated: 2023/01/13 04:08:02 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	message(char *mes, t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(&philo->data->stop[philo->index]);
	if (philo->finish)
	{
		return (ft_mutex_unlock(&philo->data->stop[philo->index], NULL, 1));
	}
	ft_mutex_unlock(&philo->data->stop[philo->index], NULL, 0);
	time = get_time() - philo->data->start;
	pthread_mutex_lock(&philo->data->print);
	printf(mes, time, philo->id);
	return (ft_mutex_unlock(&philo->data->print, NULL, 0));
}
