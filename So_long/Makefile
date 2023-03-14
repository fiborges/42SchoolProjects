NAME		= so_long

INCLUDE		= includes/
HEADER		= ${INCLUDE}so_long.h

CC			= clang
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= srcs/
SRC_NAME	= main.c					\
			  initialize_map.c			\
			  initialize_map_checker.c	\
			  initialize_window.c		\
			  initialize_img.c			\
			  initialize_game.c			\
			  game.c					\
			  exit_game.c
SRC			= ${addprefix ${SRC_DIR}, ${SRC_NAME}}

OBJ_DIR		= objs/
OBJ_DIRS	= ${sort ${dir ${OBJ}}}
OBJ_NAME	= ${SRC_NAME:.c=.o}
OBJ			= ${addprefix ${OBJ_DIR}, ${OBJ_NAME}}

all: ${NAME}

${NAME}: ${OBJ}
	@make -sC ./libft/
	@make -sC ./mlx-linux/
	${CC} ${CFLAGS} -L./libft ${OBJ} -lft -Lmlx-linux -lmlx_Linux -L/usr/lib -Ilibmlx_linux -lXext -lX11 -lm -lz -o ${NAME} -g3

${OBJ_DIRS}:
	mkdir -p ${OBJ_DIRS}

${OBJ}: ${OBJ_DIR}%.o: ${SRC_DIR}%.c ${HEADER} | ${OBJ_DIRS}
	${CC} ${CFLAGS} -I${INCLUDE} -I/usr/include -Imlx_linux -O3 -c $< -o $@ -g3

clean:
	@make clean -sC ./libft/
	@make clean -sC ./mlx-linux/
	rm -rf ${OBJ_DIR}

fclean: clean
	@make fclean -sC ./libft/
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re