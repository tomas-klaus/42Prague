/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:23:40 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/05/15 10:54:05 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 take args
    number_of_philosophers
    time_to_die, time_to_eat
    time_to_sleep
    [number_of_times_each_philosopher_must_eat]
parse args so theres 4-5 of them and theyre numbers and bigger than 0 (except the last one which can be 0)

initialize all the necessary structures
    general table
        all the args
        global mutexes
        start time
    structure for each philosophers
        forks

start simulation
    create threads
        run philosophers routines

stop simulation
    join threads
    destroy mutexes
    free table


-----------------------------------------------------------------------
philo routines

exit functions

output functions

time

 */

#include "../include/header.h"

int main(int argc, char **argv)
{
    if (argc < 5 || argc > 6)
        return (msg("Error: Invalid number of arguments\n", EXIT_FAILURE));

    if (!parse_args(argc, argv))
        return EXIT_FAILURE;
}
