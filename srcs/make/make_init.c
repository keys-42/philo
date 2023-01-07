/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:55:12 by kyoda             #+#    #+#             */
/*   Updated: 2023/01/07 15:51:45 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_make_data(t_data *data, int argc, char **argv)
{
	size_t	tmp;
	size_t	i;

	i = 0;
	data->philosophers_num = (size_t)ft_atol(argv[0]);
	data->time_to_die = (size_t)ft_atol(argv[1]);
	data->time_to_eat = (size_t)ft_atol(argv[2]);
	data->time_to_sleep = (size_t)ft_atol(argv[3]);
	if (argc == 5)
		tmp = (size_t)ft_atol(argv[4]);
	while (i < data->philosophers_num)
	{
		data->number_of_meals[i] = tmp;
		data->philo[i].id = (int)i;
		data->philo[i].data = data;
		i++;
	}
	return (0);
}

static void	ft_set_mutex(t_philo *p1, t_philo *p2)
{
	p1->fork2 = &p2->fork1;
}

int	ft_make_mutex(t_data *data)
{
	int	i;
	int	j;

	j = (int)data->philosophers_num;
	i = 0;
	while (i < j)
	{
		pthread_mutex_init(&data->philo[i].fork1, NULL);
		pthread_mutex_init(&data->last_eat_mutex[i], NULL);
		pthread_mutex_init(&data->philo[i].is_death, NULL);
		i++;
	}
	i = 0;
	while (i < j - 1)
	{
		ft_set_mutex(&data->philo[i], &data->philo[i + 1]);
		i++;
	}
	data->philo[i].fork2 = &data->philo[0].fork1;
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->death_check, NULL);
	return (0);
}

int	ft_make_thread(t_data *data)
{
	int			j;
	int			i;
	pthread_t	monitor;

	i = 0;
	j = (int)data->philosophers_num;
	data->start = (size_t)get_time();
	while (i < j)
	{
		data->last_eat_time[i] = data->start;
		if (pthread_create(&data->thread[i], NULL, philosophers,
				&data->philo[i]) != 0)
			return (1);
		i++;
	}
	if (pthread_create(&monitor, NULL, death_watch, data) != 0)
		return (1);
	pthread_join(monitor, NULL);
	i = 0;
	while (i < j)
	{
		pthread_join(data->thread[i], NULL);
		i++;
	}
	return (0);
}
