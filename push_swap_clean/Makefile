NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Path to the libft directory
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Path to the ft_print directory
FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a


SRCS_DIR = src
SRCS = $(SRCS_DIR)/main.c $(SRCS_DIR)/parse_input.c $(SRCS_DIR)/helpers.c $(SRCS_DIR)/turk_sort.c \
	$(SRCS_DIR)/stack.c $(SRCS_DIR)/simple.c $(SRCS_DIR)/instructions.c $(SRCS_DIR)/instructions2.c \
	$(SRCS_DIR)/instructions3.c $(SRCS_DIR)/helpers2.c $(SRCS_DIR)/helpers3.c $(SRCS_DIR)/execute_moves.c

OBJS = $(SRCS:.c=.o)

# Rule to build the push_swap executable
$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf

# Rule to build libft by calling its Makefile
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Rule to build ft_printf by calling its Makefile
$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Default target to build everything (both server and client)
all: $(NAME)

# Clean up object files
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

# Clean up object files and the executables
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

# Rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re