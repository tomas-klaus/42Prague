/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:21:47 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/05/15 10:42:42 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H
#include <string.h>   // memset
#include <stdio.h>    // printf
#include <stdlib.h>   // malloc, free
#include <unistd.h>   // write, usleep
#include <sys/time.h> // gettimeofday
#include <pthread.h>  // pthread_create, pthread_mutex_init ...
#include <limits.h>

/******************************************************************************
 *                           Function Prototypes                               *
 ******************************************************************************/

// parsing
int parse_args(int argc, char **argv);

// exit
int msg(char *str, int exit_no);
#endif