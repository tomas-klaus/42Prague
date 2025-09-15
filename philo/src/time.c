/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:55:23 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/09/15 12:46:47 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void setup_times(t_table *table)
{
    table->start_time = get_time();
    int i = 0;
    while (i < table->philo_count)
    {
        table->philos[i].last_meal = table->start_time;
        i++;
    }
}


time_t get_time()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

time_t get_timestamp(t_table *table)
{
	time_t timestamp = get_time() - table->start_time;
	// printf("%ld\n", get_time());
	return timestamp;
}

/* philo_sleep:
 *	Pauses the philosopher thread for a certain amount of time in miliseconds.
 *	Periodically checks to see if the simulation has ended during the sleep
 *	time and cuts the sleep short if it has.
 */
int philo_sleep(t_table table, time_t sleep_time, int id)
{
	time_t wake_up;

	wake_up = get_time() + sleep_time;
	// printf("wake up: %ld\n", wake_up);
	while (get_time() < wake_up)
	{
		// printf("%ld\n", get_time());
		pthread_mutex_lock(&table.stop_flag_mutex);
		if (table.stop_flag)
		{
			if (table.stop_flag == id)
			{
				pthread_mutex_lock(&table.write_lock);
				printf("%ld %d has died\n", get_timestamp(&table), id + 1);
				pthread_mutex_unlock(&table.write_lock);
			}
			pthread_mutex_unlock(&table.stop_flag_mutex);
			return 1;
		}
		pthread_mutex_unlock(&table.stop_flag_mutex);
		usleep(1000); // 1ms
	}
	/* pthread_mutex_lock(&table.stop_flag_mutex);
	if (table.stop_flag)
	{
		if (table.stop_flag == id)
		{
			pthread_mutex_lock(&table.write_lock);
			printf("%ld %d has died\n", get_timestamp(&table), id + 1);
			pthread_mutex_unlock(&table.write_lock);
		}
		pthread_mutex_unlock(&table.stop_flag_mutex);
		return 1;
	}
	pthread_mutex_unlock(&table.stop_flag_mutex); */
	return 0;
}
