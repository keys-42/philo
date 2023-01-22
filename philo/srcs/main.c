/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:33:48 by keys              #+#    #+#             */
/*   Updated: 2023/01/19 11:31:09 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (ft_error_print("argc is missing.\n"));
	memset(&data, 0, sizeof(t_data));
	if (ft_checks(--argc, ++argv))
		return (1);
	if (ft_make_data(&data, argc, argv))
		return (1);
	if (ft_make_mutex(&data))
		return (1);
	if (ft_make_thread(&data))
		return (1);
	return (0);
}
