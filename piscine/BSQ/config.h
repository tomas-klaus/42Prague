/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklaus <tklaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:40:29 by dmalasek          #+#    #+#             */
/*   Updated: 2024/08/28 20:08:10 by tklaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H

# define CONFIG_H
# define BUFFER_SIZE 128

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int				row_num;
	int				col_num;
	char			empty;
	char			obstacle;
	char			full;
	char			*filename;
}					t_map;

typedef struct s_MaxInfo
{
	int				value;
	int				row;
	int				col;
}					t_MaxInfo;

int					get_line_length(int line_number, char *filename);
int					get_number_of_lines(char *filename);
char				get_char_on_index(int index, char *filename);
void				throw_error(void);
int					open_file(char *filename);
int					ft_atoi(char *str);
void				append_buffer(char **line, size_t *line_len,
						const char *buffer, size_t bytes_read);
void				write_to_file(const char *filename, const char *content,
						size_t content_len);
void				*ft_realloc(void *ptr, size_t new_size);
size_t				str_len(const char *s);
void				read_first_line(char *buffer, int *n_lines, char *chars);
void				read_line(char **line, size_t *line_len);
void				read_lines(int n_lines, char **lines, size_t *total_len);
char				*read_input(void);
int					validate_map(char *filename);
struct s_map		setup(char *filename);
int					solve_map(struct s_map map);
int					is_obstacle(int **matrix, int row, int col);
int					min(int a, int b, int c);
void				fillmatrix_sq(int **matrix, int **dp_matrix, int row_size,
						int column_size);
int					find_square(int **matrix, int **dp_matrix,
						struct s_map map);
struct s_MaxInfo	find_max_in_matrix(int **matrix, int row_size,
						int column_size);
int					count_obstacles(int fd, struct s_map map);
void				handle_obstacle(int **matrix, int row, int column,
						int *obstacle);
void				process_file_data(int **matrix, int fd, struct s_map map);
int					fill_matrix(int **matrix, int fd, struct s_map map);
int					are_map_chars_valid(char *filename);
int					is_same_line_length(char *filename);
int					is_obstacle_present(char *filename);
int					is_first_line_valid(char *filename);
int					is_correct_lines(char *filename);
void				draw_square(int **matrix, struct s_MaxInfo max_info,
						int value);
void				putchar_custom(char c);
int					render_square(struct s_map map, int **dp_matrix,
						int box_value);
int					write_square(struct s_MaxInfo max_info, struct s_map map,
						int **dp_matrix);
int					free_matrix(int **matrix, int row_size);
void				output(struct s_map map, char *arg);
int					main(int argc, char *argv[]);

#endif