/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:41:50 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/12 20:43:19 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_filename(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (filename[i - 4] == '.' && filename[i - 3] == 'b' && filename[i
		- 2] == 'e' && filename[i - 1] == 'r')
		return (1);
	return (0);
}
/*
* Reallocates memory for a string
 */
char	*realloc_string(char *old_str, char *buffer, int newbytes)
{
	char	*new_str;
	int		oldbytes;
	

	oldbytes = 0;

	if (old_str)
		oldbytes = ft_strlen(old_str);
	new_str = malloc(oldbytes + newbytes);
	if (!new_str)
	{
		free(old_str);
		return (NULL);
	}
	ft_strlcpy(new_str, old_str, oldbytes);
	ft_strlcat(new_str, buffer, oldbytes + newbytes);
	if (old_str)
		free(old_str);
	return (new_str);
}

char	*read_into_map(int fd)
{
	char	buffer[BUFFER_SIZE+1];
	char	*map;
	int		bytesRead;
	int		first;

	first = 0;
	bytesRead = BUFFER_SIZE;
	while (bytesRead == BUFFER_SIZE)
	{
		bytesRead = read(fd, buffer, BUFFER_SIZE);
		buffer[bytesRead] = '\0';
		if (!first)
		{
			map = ft_strdup(buffer);
			if (!map)
				return (NULL);	
			first = 1;	
		}
		else
			map = realloc_string(map, buffer, bytesRead);
	}
	return (map);
}

char	*read_file(char *filename)
{
	char *map;
	if (!check_filename(filename))
	{
		ft_printf("Wrong format - accepted format is .ber\n");
		return (NULL);
	}
	int fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file\n");
		return (NULL);
	}
	map = read_into_map(fd); 
	if (!map)
	{
		ft_printf("Error reading file\n");
		return (NULL);
	}
	close(fd); 
	return (map);
}