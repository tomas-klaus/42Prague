# Compiler options.
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files.
#SRC_FILES = $(wildcard *.c)
SRC_FILES = bsq.c convert.c error.c file.c find_square.c find_square2.c input.c main.c map.c memory.c read.c square_obst.c validate.c write_square.c

# Object files.
OBJ_FILES = $(patsubst %.c,%.o,$(SRC_FILES))

# Dependency files.
DEP_FILES = $(patsubst %.c,%.d,$(SRC_FILES))

# Name of the resulting binary file.
BIN = bsq

# Targets.
all: $(BIN)

$(BIN): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEP_FILES)

.PHONY: clean
clean:
	rm -f $(OBJ_FILES) $(DEP_FILES)

.PHONY: fclean
fclean: clean
	rm -f $(BIN)