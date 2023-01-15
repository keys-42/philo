/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 01:39:16 by kyoda             #+#    #+#             */
/*   Updated: 2023/01/13 04:07:37 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork1);
	if (message(FORK, philo))
		return (ft_mutex_unlock(&philo->fork1, NULL, 1));
	pthread_mutex_lock(philo->fork2);
	if (message(FORK, philo))
		return (ft_mutex_unlock(&philo->fork1, philo->fork2, 2));
	return (0);
}
