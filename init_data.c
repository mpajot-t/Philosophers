/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:41:04 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/09/02 13:08:35 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	initialize_data(t_data *data, t_philo *philos)
{
	data->dead_flag = 0;
	data->philos = philos;
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
}

static void	init_args(t_philo *philos, char **args)
{
	philos->num_of_philos = ft_atoi(args[1]);
	philos->time_to_die = ft_atoi(args[2]);
	philos->time_to_eat = ft_atoi(args[3]);
	philos->time_to_sleep = ft_atoi(args[4]);
	if (args[5])
		philos->num_to_eat = ft_atoi(args[5]);
	else
		philos->num_to_eat = -1;
}

void	initialize_philos(t_philo *philos, pthread_mutex_t *forks, t_data *program, char **args)
{
	int	i;

	i = 0;
	while (i < ft_atoi(args[1]))
	{
		philos[i].phil_id = i + 1;
		philos[i].write_lock = &program->write_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].meals_eaten = 0;
		philos[i].eating = 0;
		philos[i].start_time = get_current_time();
		philos[i].last_meal = get_current_time();
		philos[i].dead = &program->dead_flag;
		philos[i].left_fork = &forks[i];
		init_args(&philos[i], args);
		if (i == 0)
			philos[i].right_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].right_fork = &forks[i - 1];
		i++;
	}
}

void	initialize_forks(pthread_mutex_t *forks, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}
