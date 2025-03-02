/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:31:17 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/02 16:31:17 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* with each signal add either 0 or 1 to a string(?) and then convert and display it all together */

char	*g_str;

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptrdest;
	unsigned char	*ptrsrc;

	if (!src || !dest)
		return (dest);
	i = 0;
	ptrdest = (unsigned char *)dest;
	ptrsrc = (unsigned char *)src;
	while (i < n)
	{
		ptrdest[i] = ptrsrc[i];
		i++;
	}
	return (dest);
}

void	add_to_str(char c)
{
	static int	i = 0;
	char		*new_str;

	new_str = malloc(i + 1);
	if (!new_str)
	{
		if (g_str)
			free(g_str);
		exit(1);
	}
	if (g_str)
	{
		ft_memcpy(new_str, g_str, i);
		free(g_str);
		g_str = NULL;
	}
	new_str[i] = c;
	g_str = new_str;
	new_str = NULL;
	i++;
	if (c == '\0')
	{
		i = 0;
		new_str = NULL;
	}
}

void	signal_handler(int signum)
{
	static int	bit_count = 0;
	static char	current_char = 0;

	if (signum == SIGUSR1)
		current_char |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		add_to_str(current_char);
		if (current_char == '\0')
		{
			ft_printf("%s", g_str);
			free(g_str);
			g_str = NULL;
		}
		bit_count = 0;
		current_char = 0;
	}
}

int	main(void)
{
	int pid;

	g_str = NULL;
	pid = getpid();
	ft_printf("The process ID is %d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		usleep(300);
	return (0);
}