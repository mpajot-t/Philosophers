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
	t_data			program;
	t_philo			philos[MAX_PHILO];
	pthread_mutex_t	forks[MAX_PHILO];

	if (argc < 5 || argc > 6)
		return (0);
	if (check_args(argv) == 0)
		return (0);
	initialize_philos(philos, forks, &program, argv);
	initialize_data(&program, philos);
}
