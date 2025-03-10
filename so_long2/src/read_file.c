/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:41:50 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/10 23:13:29 by tomasklaus       ###   ########.fr       */
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

char	*realloc_string(char *old_str, char *buffer, int newbytes)
{
	char	*new_str;
	int		oldbytes;
	int		i;

	i = 0;
	oldbytes = ft_strlen(old_str);
	new_str = malloc(oldbytes + newbytes);
	if (!new_str)
	{
		free(old_str);
		ft_printf("Error allocating memory");
	}
	ft_strlcpy(new_str, old_str, oldbytes);
	while (new_str[i])
		i++;
	ft_strlcpy(new_str, buffer, newbytes);
	free(old_str); // this may cause a segfault
	return (new_str);
}

char	*read_into_map(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*map;
	int		bytesRead;

	bytesRead = BUFFER_SIZE;
	while (bytesRead == BUFFER_SIZE)
	{
		bytesRead = read(fd, buffer, BUFFER_SIZE);
		if (bytesRead == BUFFER_SIZE)
			map = realloc_string(map, buffer, bytesRead + 1);
		else
		{
			map = malloc(bytesRead + 1);
			if (!map)
				ft_printf("Error allocating memory");
			ft_strlcpy(map, buffer, bytesRead + 1);
		}
	}
	return (map);
}

char	*read_file(char *filename)
{
	char *map;
	ft_printf("Reading file: %s\n", filename);
	if (!check_filename(filename))
		ft_printf("Wrong format");
	int fd = open(filename, O_RDONLY); // Open file for reading only
	if (fd == -1)
		ft_printf("Error opening file\n");
	map = read_into_map(fd); // Read the file
	close(fd);               // Close the file
	return (map);
}