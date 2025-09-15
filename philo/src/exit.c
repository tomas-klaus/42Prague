/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:05:25 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/09/15 19:58:00 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

/* msg:
 *	Writes a message to the console. Returns the provided exit number.
 *	Used for error management.
 */
int	msg(char *str, int exit_no)
{
	printf("%s", str);
	return (exit_no);
}

void	dest_mutex(t_table *table)
{
	int	i;

	i = 0;
	if (table->philos)
	{
		while (i < table->philo_count)
		{
			pthread_mutex_destroy(&table->philos[i].last_meal_mutex);
			pthread_mutex_destroy(&table->philos[i].times_ate_mutex);
			i++;
		}
	}
}

void	cleanup(t_table *table)
{
	int	i;

	i = 0;
	if (table->fork_mutex)
	{
		while (i < table->philo_count)
		{
			pthread_mutex_destroy(&table->fork_mutex[i]);
			i++;
		}
		free(table->fork_mutex);
	}
	dest_mutex(table);
	pthread_mutex_destroy(&table->write_lock);
	pthread_mutex_destroy(&table->stop_flag_mutex);
	if (table->fork)
		free(table->fork);
	if (table->philos)
		free(table->philos);
}
