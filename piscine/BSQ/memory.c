/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:53:10 by dmalasek          #+#    #+#             */
/*   Updated: 2024/08/28 15:00:39 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	char	*new_ptr;
	char	*old_ptr;
	size_t	i;
	size_t	old_size;

	old_ptr = ptr;
	if (!old_ptr)
		return (malloc(new_size));
	old_size = 0;
	while (old_ptr[old_size] != '\0')
		old_size++;
	old_size++;
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	i = 0;
	while (i < old_size && i < new_size)
	{
		new_ptr[i] = old_ptr[i];
		i++;
	}
	free(old_ptr);
	return (new_ptr);
}
