/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:18:12 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/08/23 10:18:12 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int	check_if_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	eat(t_philo *philo)
{

}

void	sleep(t_philo *philo)
{
	
}

void	think(t_philo *philo)
{
	printf
}

void *routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!check_if_dead(philo))
	{
		eat(philo);
		sleep(philo);
		think(philo);
	}
}
