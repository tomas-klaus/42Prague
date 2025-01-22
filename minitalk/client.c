/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:31:20 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/01/03 18:33:43 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	minus;
	int	result;

	if (!nptr)
		return (0);
	result = 0;
	i = 0;
	minus = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			minus++;
		i++;
	}
	while ((nptr[i] >= 48 && nptr[i] <= 57))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (minus)
		result *= -1;
	return (result);
}

void	send_bit(int pid, int bit)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100); // Small delay to ensure signal is received
}

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		send_bit(pid, (c >> i) & 1);
		i--;
	}
}

int	encrypt_and_send(char *msg, int pid)
{
	while (*msg)
	{
		send_char(pid, *msg);
		msg++;
	}
	// Send null character at the end of the message
	send_char(pid, '\0');
	return (0);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	/* Encrypt and send the message */
	encrypt_and_send(msg, pid);
	/* Create a stop condition so that the server knows when it has finished receiving the message */
}
