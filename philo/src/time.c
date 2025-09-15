/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:55:23 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/09/15 19:55:52 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	setup_times(t_table *table)
{
	int	i;

	table->start_time = get_time();
	i = 0;
	while (i < table->philo_count)
	{
		table->philos[i].last_meal = table->start_time;
		i++;
	}
}

time_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

time_t	get_timestamp(t_table *table)
{
	time_t	timestamp;

	timestamp = get_time() - table->start_time;
	return (timestamp);
}

int	quick_check(t_table *table, int id)
{
	pthread_mutex_lock(&table->stop_flag_mutex);
	if (table->stop_flag)
	{
		if (table->stop_flag == id)
		{
			pthread_mutex_lock(&table->write_lock);
			printf("%ld %d has died\n", get_timestamp(table), id + 1);
			pthread_mutex_unlock(&table->write_lock);
		}
		pthread_mutex_unlock(&table->stop_flag_mutex);
		return (1);
	}
	pthread_mutex_unlock(&table->stop_flag_mutex);
	return (0);
}

/* philo_sleep:
 *	Pauses the philosopher thread for a certain amount of time in miliseconds.
 *	Periodically checks to see if the simulation has ended during the sleep
 *	time and cuts the sleep short if it has.
 */
int	philo_sleep(t_table *table, time_t sleep_time, int id)
{
	time_t	wake_up;

	wake_up = get_time() + sleep_time;
	while (get_time() < wake_up)
	{
		pthread_mutex_lock(&table->stop_flag_mutex);
		if (table->stop_flag)
		{
			if (table->stop_flag == id)
			{
				pthread_mutex_lock(&table->write_lock);
				printf("%ld %d has died\n", get_timestamp(table), id + 1);
				pthread_mutex_unlock(&table->write_lock);
			}
			pthread_mutex_unlock(&table->stop_flag_mutex);
			return (1);
		}
		pthread_mutex_unlock(&table->stop_flag_mutex);
		usleep(1000);
	}
	return (0);
}
