/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:48:05 by kyoda             #+#    #+#             */
/*   Updated: 2023/01/07 15:39:57 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_digit(int i, int j, char **argv)
{
	while (argv[i][j])
	{
		if (ft_isdigit(argv[i][j]))
			j++;
		else
			return (ft_error_print("Contains non-numbers"));
	}
	return (0);
}

static int	ft_check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (ft_isspace(argv[i][j]))
			j++;
		if ((argv[i][j]) == '-')
			return (ft_error_print("Contains a minus"));
		else if ((argv[i][j]) == '+')
		{
			j++;
			if ((argv[i][j]) == '\0')
				return (ft_error_print("invalid argument +"));
		}
		if (ft_check_digit(i, j, argv))
			return (1);
		i++;
	}
	return (0);
}

int	ft_checks(t_data *data, int argc, char **argv)
{
	if (ft_check_arg(argc, argv))
		return (1);
	memset(data, 0, 0);
	return (0);
}
