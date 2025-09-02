/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:17:01 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/08/25 10:57:45 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int	ft_atoi(char *nptr)
{
	int	sign;
	int	i;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (num * sign);
}

static int	check_args(char *args)
{
	int	i;

	i = 0;
    while (args[i])
    {
		if (args[i] < '0' && args[i] > '9')
			return (1);
		i++;
    }
	return (0);
}

int	check_params(char **args)
{
	if (ft_atoi(args[1]) <= 0 || ft_atoi(args[1]) > MAX_PHILO || check_args(args[1]) == 1)
		return(write(2, "Philo numbers is invalid", 25), 1);
	else if (ft_atoi(args[2]) <= 0 || check_args(args[2]) == 1)
		return(write(2, "Time to die is invalid", 23), 1);
	else if (ft_atoi(args[3]) <= 0 || check_args(args[3]) == 1)
		return(write(2, "Time to eat is invalid", 23), 1);
	else if (ft_atoi(args[4]) <= 0 || check_args(args[4]) == 1)
		return(write(2, "Time to sleep is invalid", 23), 1);
	else if (args[5] && (ft_atoi(args[5]) < 0 || check_args(args[5]) == 1))
		return(write(2, "Number of times each philo must eat is invalid", 47), 1);
	return (0);
}
