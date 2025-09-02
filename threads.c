/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:48:08 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/09/02 13:57:04 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

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

int	initliaze_threads(t_data *data, pthread_mutex_t *forks)
{
	pthread_t	monitoring;
	int			i;

	i = 0;
	if (pthread_create(&monitoring, NULL, &overseer, data->philos) != 0)
		destroy_all("Erreur creation thread monitoring", data, forks);
	while (i < data->philos[0].num_of_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &routine, &data->philos[i]) != 0)
			destroy_all("Erreur creation thread philo", data, forks);
		i++;
	}
	i = 0;
	if (pthread_join(monitoring, NULL) != 0)
		destroy_all("Erreur join thread monitoring", data, forks);
	while (i < data->philos[0].num_of_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			destroy_all("Erreur join thread philo", data, forks);
		i++;
	}
	return (0);
}