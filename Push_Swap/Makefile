NAME	= push_swap

SRC		= push_swap.c \
		utils_01.c \
		utils_02.c \
		utils_03.c \
		operations_01.c \
		operations_02.c \
		short_list_01.c \
		short_list_02.c \
		long_list.c

DIR 	= ${addprefix srcs/,${SRC}}

HEAD	= -I libft -I include

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror -g

OBJS 	= ${DIR:.c=.o}

LD_FLAG	= -L libft

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(LD_FLAG) $(OBJS) -lft


.c.o:
	${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
