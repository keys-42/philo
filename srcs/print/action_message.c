/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_message.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:30:11 by keys              #+#    #+#             */
/*   Updated: 2022/12/31 23:41:58 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action_message(char *mes, t_philo *philo)
{
	if (get_deth_flag(philo))
		return ;
	pthread_mutex_lock(&philo->data->print);
	printf(mes, get_time() - philo->data->start, philo->id);
	pthread_mutex_unlock(&philo->data->print);
}
