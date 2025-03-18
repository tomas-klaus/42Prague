NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a


SRCS_DIR = src
CFILES = $(SRCS_DIR)/main.c $(SRCS_DIR)/parse_input.c $(SRCS_DIR)/helpers.c $(SRCS_DIR)/turk_sort.c \
	$(SRCS_DIR)/stack.c $(SRCS_DIR)/simple.c $(SRCS_DIR)/instructions.c $(SRCS_DIR)/instructions2.c \
	$(SRCS_DIR)/instructions3.c $(SRCS_DIR)/helpers2.c $(SRCS_DIR)/helpers3.c $(SRCS_DIR)/execute_moves.c

OBJECTS = $(CFILES:.c=.o)

all: subsystems $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

subsystems:
	@make -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_LIB) -o $(NAME)

clean:
	
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norm