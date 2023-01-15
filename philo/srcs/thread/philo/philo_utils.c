/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:02:05 by kyoda             #+#    #+#             */
/*   Updated: 2023/01/13 04:00:08 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_mutex_unlock(pthread_mutex_t *mutex1, pthread_mutex_t *mutex2, int flag)
{
	pthread_mutex_unlock(mutex1);
	if (flag == 0)
		return (0);
	else if (flag == 1)
		return (1);
	pthread_mutex_unlock(mutex2);
	return (flag);
}
