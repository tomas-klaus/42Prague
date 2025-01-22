NAMEC = client
NAMES = server
BONUS_NAMEC = client_bonus
BONUS_NAMES = server_bonus
PRINTF = libftprintf.a
SRCC_FILES =	client.c
SRCS_FILES =	server.c
BONUSC_FILES = client_bonus.c 
BONUSS_FILES = server_bonus.c
SRCC = $(SRCC_FILES)
SRCS = $(SRCS_FILES)
BONUSC = $(BONUSC_FILES)
BONUSS = $(BONUSS_FILES)
OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}
OBJBC = ${BONUSC:.c=.o}
OBJBS = ${BONUSS:.c=.o}
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

all:	$(NAMEC) $(NAMES)

$(NAMEC) : $(OBJC)
		@make -C ft_print
		$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) ft_print/$(PRINTF) -o $(NAMEC)

$(NAMES) : $(OBJS)
		@make -C ft_print
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) ft_print/$(PRINTF) -o $(NAMES)

bonus : $(BONUS_NAMEC) $(BONUS_NAMES)

$(BONUS_NAMEC) : $(OBJBC)
				@make -C ft_print
				$(CC) $(CFLAGS) $(OBJBC)  $(INCLUDE)  ft_print/$(PRINTF) -o $(BONUS_NAMEC)

$(BONUS_NAMES) : $(OBJBS)
				@make -C ft_print
				$(CC) $(CFLAGS) $(OBJBS)  $(INCLUDE)  ft_print/$(PRINTF) -o $(BONUS_NAMES)

clean :
		@make clean -C ft_print
		${RM} ${OBJC}
		${RM} ${OBJS}
		${RM} ${OBJBC}
		${RM} ${OBJBS}

fclean : clean
		@make fclean -C ft_print
		${RM} $(NAMEC)
		${RM} $(NAMES)
		${RM} $(BONUS_NAMEC)
		${RM} $(BONUS_NAMES)
		${RM} $(PRINTF)

re : fclean all

.PHONY:		all bonus clean fclean re