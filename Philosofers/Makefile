NAME		=	philo

HEADER		=	./include/

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra -g -I $(HEADER) -pthread

SRCS		=	srcs/main.c \
				srcs/state.c \
				srcs/threads.c \
				srcs/parsing_init.c \
				srcs/utils2.c \
				srcs/utils3.c \
				srcs/utils.c \

OBJS		=	$(SRCS:.c=.o)

# Cores
RED			=	\033[0;31m
GREEN		=	\033[0;32m
NC			=	\033[0m

# Mensagem personalizada
COMPILE_MSG	=	"Compilação concluída com sucesso"

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
				@echo "$(GREEN)$(COMPILE_MSG)$(NC)"

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -rf $(NAME)
				@echo "$(RED)Todos os arquivos foram apagados com sucesso$(NC)"

re			:	fclean all

tsan        :   clean $(OBJS) $(HEADER)
				$(CC) $(CFLAGS) -fsanitize=thread $(OBJS) -o $(NAME)
				./$(NAME) $(ARGS)

valgrind	:	clean $(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
				valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(NAME) $(ARGS)



# make tsan ARGS="5 800 200 200"
# make valgrind ARGS="5 800 200 200"
