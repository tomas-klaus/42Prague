/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:00:53 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/25 21:50:38 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * A library of useful default functions.
 */

#ifndef LIB_FT_H
# define LIB_FT_H

/**
 * For ft_is_printable().
 */
# define PRINTABLE_LOWER	32
# define PRINTABLE_UPPER	126

/**
 * If buffer is not big enough, those values will be used
 * in calculation of a new buffer's size.
 */
# define BUFF_INC	10
# define BUFF_MULT	1.3

# include <stddef.h>
# include <sys/types.h>

int		ft_fd_putchar(int fd, char c);
int		ft_count_digits(int num);
int		ft_fd_putnbr(int fd, int nb);
void	ft_swap(void *a, void *b, unsigned int n);
int		ft_fd_putstr(int fd, const char *str);
size_t	ft_strlen(const char *s);
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_is_printable(int c);
char	*ft_realloc_str(char *str, unsigned int old_buff_size,
			unsigned int new_buff_size);
int		ft_extend_str(char **str, size_t *n);
ssize_t	ft_fd_getline(char **lineptr, size_t *n, int fd);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int n);

#endif	/* LIB_FT_H */
