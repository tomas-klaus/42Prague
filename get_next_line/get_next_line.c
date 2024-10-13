/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:49:32 by tomasklaus        #+#    #+#             */
/*   Updated: 2024/10/11 15:38:03 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
1. read() up to [BUFFER_SIZE] bytes
2. realloc an array of size [BUFFER_SIZE]
3. see if the buffer contains \n or \0 at the end
4. append data from buffer to array
5. if the bytes read is the size of the buffer and theres no null terminator,
	run again

 */
size_t	read_one_buffer(int fd, char *buffer)
{
	size_t	bytes_read;
	size_t	i;

	bytes_read = read(fd, buffer, BUFFER_SIZE-1);
	i = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	char	*arr;
    int first = 1;

	if (fd == -1)
		return (NULL);
	while (1)
	{
        
		bytes_read = read_one_buffer(fd, buffer);
        printf("bytes_read: %ld\n", bytes_read);
		if (first)
		{
            first = 0;
			arr = ft_realloc_str(buffer, sizeof(buffer), bytes_read);
            printf("sizeof(arr) in first: %ld\n", sizeof(arr));
            printf("arr: %s\n", arr);
			if (!arr)
				return (NULL);
		}
		else
		{
            printf("sizeof(arr): %ld\n", sizeof(arr));
			arr = ft_realloc_str(arr, sizeof(arr), sizeof(arr) + bytes_read);
            
			if (!arr)
				return (NULL);
		}
		if (bytes_read != BUFFER_SIZE)
			return (arr);
	}
}

#include <fcntl.h>
int main()
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("%s\n", line);
    return (0);
}