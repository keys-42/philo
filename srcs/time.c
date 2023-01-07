/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:40:59 by keys              #+#    #+#             */
/*   Updated: 2023/01/07 15:44:24 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	time_result;
	size_t			time;
	int				flag;

	flag = 0;
	flag = gettimeofday(&time_result, NULL);
	time = time_result.tv_sec * 1000 + time_result.tv_usec / 1000;
	return (time);
}
