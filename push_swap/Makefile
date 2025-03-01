NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a



CFILES = main.c parse_input.c helpers.c

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