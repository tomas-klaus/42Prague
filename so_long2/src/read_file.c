/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:41:50 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/11 12:35:44 by tklaus           ###   ########.fr       */
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
	int		i;
	char *temp;

	oldbytes = 0;
	i = 0;
	if (old_str)
		oldbytes = ft_strlen(old_str);
	ft_printf("oldbytes: %d\n", oldbytes);
	ft_printf("newbytes: %d\n", newbytes);
	new_str = malloc(oldbytes + newbytes);
	if (!new_str)
	{
		free(old_str);
		ft_printf("Error allocating memory");
	}
	ft_strlcpy(new_str, old_str, oldbytes);
	temp = new_str;
	while (*new_str)
		new_str++;
	//ft_printf("buffer: %s\n", buffer);
	ft_strlcpy(new_str, buffer, newbytes);
	if (old_str)
		free(old_str); // this may cause a segfault
	return (temp);
}

char	*read_into_map(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*map;
	int		bytesRead;
	int		first;

	first = 0;
	bytesRead = BUFFER_SIZE;
	while (bytesRead == BUFFER_SIZE)
	{
		bytesRead = read(fd, buffer, BUFFER_SIZE);
		ft_printf("buffer: %s\n", buffer);
		ft_printf("bytesRead: %d\n", bytesRead);
		if (!first)
		{
			map = ft_strdup(buffer);
			first = 1;
			
		}
		else
			map = realloc_string(map, buffer, bytesRead + 1);
	}
	ft_printf("map: %s\n", map);
	return (map);
}

char	*read_file(char *filename)
{
	char *map;
	// ft_printf("Reading file: %s\n", filename);
	if (!check_filename(filename))
	{
		ft_printf("Wrong format - accepted format is .ber\n");
		return (NULL);
	}
	int fd = open(filename, O_RDONLY); // Open file for reading only
	if (fd == -1)
	{
		ft_printf("Error opening file\n");
		return (NULL);
	}
	map = read_into_map(fd); // Read the file
	if (!map)
	{
		ft_printf("Error reading file\n");
		return (NULL);
	}
	close(fd); // Close the file
	return (map);
}