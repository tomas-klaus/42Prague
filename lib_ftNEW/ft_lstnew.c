/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:51:35 by tklaus            #+#    #+#             */
/*   Updated: 2024/10/03 13:20:08 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*
#include <stdio.h>

int	main(void) {
	// Test ft_lstnew with an integer
	int value = 42;

	// Call ft_lstnew to create a new node with the integer value
	t_list *node = ft_lstnew(&value);

	// Check if the node was created successfully
	if (node == NULL) {
		printf("Memory allocation failed.\n");
		return (1); // Exit if the node creation failed
	}

	// Print the content of the node (dereference and cast content to int*)
	printf("Node content: %d\n", *(int *)(node->content));

	// Free the allocated memory for the node
	free(node);

	return (0);
} */