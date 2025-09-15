/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:02:26 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/09/15 19:58:46 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	fork_routine(t_table *table, int id)
{
	int	first;
	int	second;

	assign_forks(&first, &second, table, id);
	pthread_mutex_lock(&table->fork_mutex[first]);
	table->fork[first] = id;
	pthread_mutex_lock(&table->write_lock);
	printf("%ld %d has taken a fork\n", get_timestamp(table), id + 1);
	pthread_mutex_unlock(&table->write_lock);
	pthread_mutex_lock(&table->fork_mutex[second]);
	table->fork[second] = id;
	pthread_mutex_lock(&table->write_lock);
	printf("%ld %d has taken a fork\n", get_timestamp(table), id + 1);
	pthread_mutex_unlock(&table->write_lock);
}

int	eat_routine(t_table *table, int id)
{
	int	first;
	int	second;
	int	err;

	err = 0;
	pthread_mutex_lock(&table->philos[id].last_meal_mutex);
	table->philos[id].last_meal = get_time();
	pthread_mutex_unlock(&table->philos[id].last_meal_mutex);
	pthread_mutex_lock(&table->write_lock);
	printf("%ld %d is eating\n", get_timestamp(table), id + 1);
	pthread_mutex_unlock(&table->write_lock);
	pthread_mutex_lock(&table->philos[id].times_ate_mutex);
	table->philos[id].times_ate++;
	pthread_mutex_unlock(&table->philos[id].times_ate_mutex);
	if (philo_sleep(table, table->eat_time, id))
		err = 1;
	assign_forks(&first, &second, table, id);
	table->fork[second] = -1;
	pthread_mutex_unlock(&table->fork_mutex[second]);
	table->fork[first] = -1;
	pthread_mutex_unlock(&table->fork_mutex[first]);
	return (err);
}

int	sleep_routine(t_table *table, int id)
{
	pthread_mutex_lock(&table->write_lock);
	printf("%ld %d is sleeping\n", get_timestamp(table), id + 1);
	pthread_mutex_unlock(&table->write_lock);
	if (philo_sleep(table, table->sleep_time, id))
		return (1);
	return (0);
}

void	loop(t_table *table, int id)
{
	while (1)
	{
		if (quick_check(table, id))
			break ;
		fork_routine(table, id);
		if (quick_check(table, id))
			break ;
		if (eat_routine(table, id))
			break ;
		if (quick_check(table, id))
			break ;
		if (sleep_routine(table, id))
			break ;
		if (quick_check(table, id))
			break ;
		pthread_mutex_lock(&table->write_lock);
		printf("%ld %d is thinking\n", get_timestamp(table), id + 1);
		pthread_mutex_unlock(&table->write_lock);
	}
}

void	*philo_loop(void *arg)
{
	t_thread_data	*data;
	t_table			*table;
	int				id;

	data = (t_thread_data *)arg;
	table = data->table;
	id = data->id;
	if ((id + 1) % 2 == 0)
	{
		pthread_mutex_lock(&table->write_lock);
		printf("%ld %d is thinking\n", get_timestamp(table), id + 1);
		pthread_mutex_unlock(&table->write_lock);
		usleep(50);
	}
	loop(table, id);
	return (NULL);
}
