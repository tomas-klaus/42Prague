/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:23:40 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/09/15 13:04:25 by tomasklaus       ###   ########.fr       */
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
MUTEXES TO ADD:
-times_ate
-write_lock
-last_meal

TODO:
single philosopher
cleanup

*/

#include "../include/header.h"

void single_philo(t_table table){
    printf("0 1 has taken a fork\n");
    usleep(table.die_time*100);
    printf("%ld 1 has died\n", table.die_time);
}

void print_table(t_table table)
{
    printf("philo_count: %d\n", table.philo_count);
    printf("die_time: %ld\n", table.die_time);
    printf("eat_time: %ld\n", table.eat_time);
    printf("sleep_time: %ld\n", table.sleep_time);
    printf("must_eat_count: %d\n", table.must_eat_count);
    printf("stop_flag: %d\n", table.stop_flag);
    printf("start_time: %ld\n", table.start_time);
    int k = 0;
    while (k < table.philo_count)
    {
        printf("Philo %d: id=%d, times_ate=%d, last_meal=%ld\n",
               k + 1, table.philos[k].id, table.philos[k].times_ate, table.philos[k].last_meal);
        k++;
    }
    printf("Simulation start time: %ld\n", table.start_time);
}

int run_sim(t_table table)
{

    int i = 0;

    setup_times(&table);

    // print_table(table); //for testing
    pthread_mutex_init(&table.write_lock, NULL);
    pthread_mutex_init(&table.stop_flag_mutex, NULL);
    pthread_create(&table.obs_thread, NULL, obs_loop, &table);
    thread_data_t **data = malloc(sizeof(thread_data_t) * table.philo_count);
    while (i < table.philo_count)
    {
        pthread_mutex_init(&table.philos[i].last_meal_mutex, NULL);
        pthread_mutex_init(&table.philos[i].times_ate_mutex, NULL);
        pthread_mutex_init(&table.fork_mutex[i], NULL);
        data[i] = malloc(sizeof(thread_data_t));
        data[i]->id = i;
        data[i]->table = &table;
        // printf("Thread data: id = %d, table.philo_count = %d\n", data->id, data->table->philo_count);
        pthread_create(&table.philos[i].thread, NULL, philo_loop, data[i]);
        i++;
    }
    pthread_join(table.obs_thread, NULL);
    i = 0;
    while (i < table.philo_count)
    {
        pthread_join(table.philos[i].thread, NULL);
        free(data[i]);
        i++;
    }
    free(data);
    return SUCCESS;
}

int main(int argc, char **argv)
{
    t_table table;
    if (argc < 5 || argc > 6)
        return (msg("Error: Invalid number of arguments\n", EXIT_FAILURE));

    if (!parse_args(argc, argv))
        return (msg("Error: Parsing error\n", EXIT_FAILURE));

    table = init_structs(argc, argv);
    if (table.philo_count == 0)
        return (msg("Error: Init error\n", EXIT_FAILURE));
    //print_table(table);
    if (table.philo_count == 1)
    {
        single_philo(table);
        cleanup(table);
        return 0;
    }
    run_sim(table);
    cleanup(table);
    return 0;
}
