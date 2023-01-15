/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:40:59 by keys              #+#    #+#             */
/*   Updated: 2023/01/15 18:34:25 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	time_result;
	size_t			time;

	gettimeofday(&time_result, NULL);
	time = time_result.tv_sec * 1000 + time_result.tv_usec / 1000;
	return (time);
}
