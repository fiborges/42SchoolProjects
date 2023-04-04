NAME			= so_long

INCLUDE			= includes/

HEADER			= ${INCLUDE}so_long.h

CC				= clang

CFLAGS			= -Wall -Wextra -Werror

SRC_NAME		= main.c					\
				  initialize_map.c			\
				  initialize_map_utils.c	\
				  initialize_map_checker.c	\
				  initialize_window.c		\
				  initialize_img.c			\
				  initialize_game.c			\
				  map_utils.c				\
				  game.c					\
				  exit_game.c				

SRC_DIR			= src/
SRC				= ${addprefix ${SRC_DIR}, ${SRC_NAME}}

OBJ_DIR			= objs/
OBJ_DIRS		= ${sort ${dir ${OBJ}}}
OBJ_NAME		= ${SRC_NAME:.c=.o}
OBJ				= ${addprefix ${OBJ_DIR}, ${OBJ_NAME}}

# Defining colors
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
CYAN			= \033[0;36m
RED				= \033[0;31m
RESET			= \033[0m

all: ${NAME}

$(NAME): $(OBJ)
	@printf "${YELLOW}Compiling libft...${RESET}\n"
	@make -sC ./libft/
	@printf "${YELLOW}Compiling mlx-linux...${RESET}\n"
	@make -sC ./mlx-linux/
	@printf "${GREEN}Compiling project...${RESET}\n"
	$(CC) $(CFLAGS) -L./libft ${OBJ} -lft -Lmlx-linux -lmlx_Linux -L/usr/lib -Ilibmlx_linux -lXext -lX11 -lm -lz -o $(NAME) -g3

${OBJ_DIRS}:
	mkdir -p $@

${OBJ}: ${OBJ_DIR}%.o: ${SRC_DIR}%.c ${HEADER} | ${OBJ_DIRS}
	@printf "${CYAN}Compiling object file: $@${RESET}\n"
	${CC} ${CFLAGS} -I${INCLUDE} -I/usr/include -Imlx_linux -O3 -c $< -o $@ -g3

clean:
	@printf "${YELLOW}Cleaning libft...${RESET}\n"
	@make clean -sC ./libft/
	@printf "${YELLOW}Cleaning mlx-linux...${RESET}\n"
	@make clean -sC ./mlx-linux/
	@printf "${RED}Removing object files...${RESET}\n"
	rm -rf ${OBJ_DIR}

fclean: clean
	@printf "${RED}Removing libft binary...${RESET}\n"
	@make fclean -sC ./libft/
	@printf "${RED}Removing project binary...${RESET}\n"
	rm -f ${NAME}

re: fclean all

# New rule to check for memory leaks
check_leaks: $(NAME)
	@printf "${YELLOW}Checking for memory leaks...${RESET}\n"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(NAME)

.PHONY : all clean fclean re check_leaks


