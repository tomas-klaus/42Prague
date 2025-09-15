/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:05:25 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/09/15 10:43:37 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

/* msg:
 *	Writes a message to the console. Returns the provided exit number.
 *	Used for error management.
 */
int msg(char *str, int exit_no)
{

	printf("%s", str);

	return (exit_no);
}

void cleanup(t_table table)
{
	int i;
	i = 0;
	// Destroy fork mutexes
	if (table.fork_mutex)
	{
		while (i < table.philo_count)
		{
			pthread_mutex_destroy(&table.fork_mutex[i]);
			i++;
		}
		free(table.fork_mutex);
	}
	// Destroy philosopher threads' mutexes if any (none in t_philo)
	// Destroy write and stop_flag mutexes
	pthread_mutex_destroy(&table.write_lock);
	pthread_mutex_destroy(&table.stop_flag_mutex);
	// Free philosophers array
	if (table.philos)
		free(table.philos);
}
