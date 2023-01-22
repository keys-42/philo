/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 01:39:13 by kyoda             #+#    #+#             */
/*   Updated: 2023/01/22 11:42:35 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_sleep(t_philo *philo)
{
	size_t	start;

	if (message(SLEEP, philo))
		return (1);
	start = get_time();
	while (get_time() - start < philo->data->time_to_sleep)
		usleep(100);
	return (0);
}
