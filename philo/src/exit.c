/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:05:25 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/05/15 10:42:34 by tomasklaus       ###   ########.fr       */
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
