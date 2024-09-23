/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:35:03 by asagymba          #+#    #+#             */
/*   Updated: 2024/08/25 21:33:44 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Literally everything else used by this program.
 */

#ifndef FT_SOLVE_H
# define FT_SOLVE_H

# include <stddef.h>

/**
 * A list.
 */
struct	s_dict_entry
{
	char				*key;
	char				*value;
	struct s_dict_entry	*next;
};

int					ft_check_nb(const char *nb);
void				ft_skip_spaces(const char **s);
int					ft_dict_entry_check_rules(const char *dict_entry);
char				*ft_get_key(const char *dict_entry);
void				ft_skip_dict_entry_until_value(const char **dict_entry);
struct s_dict_entry	*ft_parse_node(const char *dict_entry);
int					ft_prepare_next_dict_node(struct s_dict_entry **next_node,
						int fd);
void				ft_free_s_dict_entry_list(struct s_dict_entry *root);
int					ft_all_chars_in_str_are_zeroes(const char *str);
int					ft_s_dict_entry_key_is_good(struct s_dict_entry *entry);
struct s_dict_entry	*ft_s_dict_entry_append(struct s_dict_entry *root,
						struct s_dict_entry *next_node);
struct s_dict_entry	*ft_parse_dict(const char *dict_file_name);
void				ft_skip_zeroes(const char **nb);
size_t				ft_get_biggest_key(const struct s_dict_entry *dict);
char				*ft_get_word_for_digit(const struct s_dict_entry *dict,
						char *nb);
char				*ft_get_word_for_tens(const struct s_dict_entry *dict,
						char *nb);
char				*ft_get_word_by_len(const struct s_dict_entry *dict,
						char *nb);
void				ft_print_word(const char *word);
int					ft_print_hundreds(const struct s_dict_entry *dict,
						char *nb);
int					ft_print_two_digits(const struct s_dict_entry *dict,
						char *nb);
int					ft_print_three_tens_power_word(
						const struct s_dict_entry *dict, char *nb);
int					ft_print_digit_and_word(const struct s_dict_entry *dict,
						char *nb);
int					ft_print_words(const struct s_dict_entry *dict,
						char *nb);

int					ft_solve(const char *dict_file_name, char *nb);

#endif	/* FT_SOLVE_H */
