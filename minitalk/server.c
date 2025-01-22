/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:31:17 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/01/03 18:26:25 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* with each signal add either 0 or 1 to a string(?) and then convert and display it all together */
void	signal_handler(int signum)
{
	static int	bit_count = 0;
	static char	current_char = 0;

	if (signum == SIGUSR1)
		current_char |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == '\0')
			exit(0);
		ft_printf("%c", current_char);
		bit_count = 0;
		current_char = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("The process ID is %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}

