/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:23:58 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/08/25 11:26:29 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int main(int argc, char **argv)
{
	t_data			data;
	t_philo			philos[MAX_PHILO];
	pthread_mutex_t	forks[MAX_PHILO];

	if (argc < 5 || argc > 6)
		return (printf("Nombre d'arguments invalide"), 1);
	if (check_params(argv))
		return (1);
	initialize_forks(forks, ft_atoi(argv[1]));
	initialize_philos(philos, forks, &data, argv);
	initialize_data(&data, philos);
	initliaze_threads(&data, forks);
	destroy_all(NULL, &data, forks);
	return (0);
}
