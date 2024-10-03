# Compiler options.
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files.
SRC_FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
            ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
            ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strrchr.c \
            ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
            ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
            ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
            ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

BONUS_FILES = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
              ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

# Object files.
OBJ_FILES = $(patsubst %.c,%.o,$(SRC_FILES))
BONUS_OBJ_FILES = $(patsubst %.c,%.o,$(BONUS_FILES))

# Dependency files.
DEP_FILES = $(patsubst %.c,%.d,$(SRC_FILES)) \
            $(patsubst %.c,%.d,$(BONUS_FILES))

# Name of the resulting binary file.
NAME = libft.a

# Targets.
all: $(NAME)

$(NAME): $(OBJ_FILES) $(BONUS_OBJ_FILES)
	ar rcs $@ $(OBJ_FILES) $(BONUS_OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEP_FILES)

.PHONY: clean
clean:
	rm -f $(OBJ_FILES) $(BONUS_OBJ_FILES) $(DEP_FILES)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: bonus
bonus: $(BONUS_OBJ_FILES)
	ar rcs $(NAME) $(BONUS_OBJ_FILES)

re: fclean all
