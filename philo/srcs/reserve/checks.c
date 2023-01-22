/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:48:05 by kyoda             #+#    #+#             */
/*   Updated: 2023/01/19 11:31:03 by keys             ###   ########.fr       */
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
			return (ft_error_print("Contains non-numbers\n"));
	}
	return (0);
}

int	ft_checks(int argc, char **argv)
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
			return (ft_error_print("Contains a minus\n"));
		else if ((argv[i][j]) == '+')
		{
			j++;
			if ((argv[i][j]) == '\0')
				return (ft_error_print("invalid argument +\n"));
		}
		if (ft_check_digit(i, j, argv))
			return (1);
		i++;
	}
	return (0);
}
