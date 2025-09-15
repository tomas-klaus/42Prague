/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:23:40 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/09/15 19:58:28 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
number_of_philosophers
time_to_die
time_to_eat
time_to_sleep
number_of_times_each_philosopher_must_eat (optional argument)
*/

/*
-mutex to protect that a philosopher dies and starts eating at the same time?
-forks musi byt neco s hodnotou a mutexy je musi jen kontrolovat
check that the output is not scrambled
odebrat hlasku "all philos have eaten..."
check the 10ms time limit
get rid of ternary ops
odebrat file.txt a out.txt



*/

#include "../include/header.h"

void	single_philo(t_table *table)
{
	printf("0 1 has taken a fork\n");
	usleep(table->die_time * 100);
	printf("%ld 1 has died\n", table->die_time);
	free(table->fork_mutex);
	free(table->philos);
}

void	print_table(t_table table)
{
	int	k;

	printf("philo_count: %d\n", table.philo_count);
	printf("die_time: %ld\n", table.die_time);
	printf("eat_time: %ld\n", table.eat_time);
	printf("sleep_time: %ld\n", table.sleep_time);
	printf("must_eat_count: %d\n", table.must_eat_count);
	printf("stop_flag: %d\n", table.stop_flag);
	printf("start_time: %ld\n", table.start_time);
	k = 0;
	while (k < table.philo_count)
	{
		printf("Philo %d: id=%d, times_ate=%d, last_meal=%ld\n", k + 1,
			table.philos[k].id, table.philos[k].times_ate,
			table.philos[k].last_meal);
		k++;
	}
	printf("Simulation start time: %ld\n", table.start_time);
	printf("----------------------------------------------------------\n\n");
}

t_thread_data	**create_threads(t_table *table)
{
	int				i;
	t_thread_data	**data;

	i = 0;
	data = malloc(sizeof(t_thread_data *) * table->philo_count);
	while (i < table->philo_count)
	{
		pthread_mutex_init(&table->philos[i].last_meal_mutex, NULL);
		pthread_mutex_init(&table->philos[i].times_ate_mutex, NULL);
		data[i] = malloc(sizeof(t_thread_data));
		data[i]->id = i;
		data[i]->table = table;
		pthread_create(&table->philos[i].thread, NULL, philo_loop, data[i]);
		i++;
	}
	return (data);
}

int	run_sim(t_table *table)
{
	t_thread_data	**data;
	int				i;

	setup_times(table);
	pthread_mutex_init(&table->write_lock, NULL);
	pthread_mutex_init(&table->stop_flag_mutex, NULL);
	pthread_create(&table->obs_thread, NULL, obs_loop, table);
	data = create_threads(table);
	pthread_join(table->obs_thread, NULL);
	i = 0;
	while (i < table->philo_count)
	{
		pthread_join(table->philos[i].thread, NULL);
		free(data[i]);
		i++;
	}
	free(data);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5 || argc > 6)
		return (msg("Error: Invalid number of arguments\n", EXIT_FAILURE));
	if (!parse_args(argc, argv))
		return (msg("Error: Parsing error\n", EXIT_FAILURE));
	table = init_structs(argv);
	if (table.philo_count == 0)
		return (msg("Error: Init error\n", EXIT_FAILURE));
	if (table.philo_count == 1)
	{
		single_philo(&table);
		return (0);
	}
	run_sim(&table);
	cleanup(&table);
	return (0);
}
