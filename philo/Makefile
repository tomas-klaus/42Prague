NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -MMD -MP

OBJ_DIR = obj

SRCS_DIR = src
SRCS = $(SRCS_DIR)/main.c \
$(SRCS_DIR)/parsing.c \
$(SRCS_DIR)/exit.c \
$(SRCS_DIR)/init.c \

OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

# Rule to build the push_swap executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Rule to compile .c files into .o files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/$(SRCS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Include dependency files
-include $(DEPS)

# Default target to build everything (both server and client)
all: $(NAME)

# Clean up object files
clean:
	rm -rf $(OBJ_DIR)

# Clean up object files and the executables
fclean: clean
	rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re