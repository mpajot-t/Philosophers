/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:23:40 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/08/25 11:28:49 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define MAX_PHILO 200

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t			thread;
	int					*dead;
	int					num_of_philos;
	int					meals_eaten;
	int					eating;
	int					last_meal;
	int					phil_id;
	size_t				start_time;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	int					num_to_eat;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*write_lock;
	pthread_mutex_t		*dead_lock;
	pthread_mutex_t		*meal_lock;
}	t_philo;

typedef struct s_data
{
	t_philo			*philos;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	int				dead_flag;
	
}	t_data;

int		check_args(char **args);
int		ft_atoi(char *nptr);
void	initialize_data(t_data *program, t_philo *philos);
void	initialize_philos(t_philo *philos, pthread_mutex_t *forks, t_data *program, char **args);
#endif