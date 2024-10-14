# Compiler options.
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files.
SRC_FILES = $(wildcard *.c)


# Object files.
OBJ_FILES = $(patsubst %.c,%.o,$(SRC_FILES))


# Dependency files.
DEP_FILES = $(patsubst %.c,%.d,$(SRC_FILES))
            

# Name of the resulting binary file.
NAME = libftprintf.a

# Targets.
all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $@ $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEP_FILES)

.PHONY: clean
clean:
	rm -f $(OBJ_FILES) $(DEP_FILES)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

re: fclean all
