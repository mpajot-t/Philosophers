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

int	check_if_dead_loop(t_philo *philo)
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
	pthread_mutex_lock(philo->right_fork);
	prog_message("has taken a fork", philo, philo->phil_id);
	if (philo->num_of_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	prog_message("has taken a fork", philo, philo->phil_id);
	philo->eating = 1;
	prog_message("is eating", philo, philo->phil_id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_sleep(t_philo *philo)
{
	prog_message("is sleeping", philo, philo->phil_id);
}

void	think(t_philo *philo)
{
	prog_message("is thinking", philo, philo->phil_id);
}

void *routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->phil_id % 2 == 0)
		ft_usleep(1);
	while (!check_if_dead_loop(philo))
	{
		eat(philo);
		ft_sleep(philo);
		think(philo);
	}
	return (pointer);
}
