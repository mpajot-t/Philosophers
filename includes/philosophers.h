/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:23:40 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/08/21 12:46:29 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h> 

typedef struct s_philo
{
	pthread_t		thread;
	int				phil_id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_to_eat;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	left_fork;
	
}	t_philo;

int	check_params(char **args);
#endif