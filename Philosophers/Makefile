NAME = philo

CC = gcc

CFLAGS = -Wall -Werror -Wextra -pthread


Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

CFILES = main.c src/initialization.c src/utils.c \
			src/threads.c src/states.c src/utils2.c \

OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf $(UP)$(CUT)

$(NAME): $(OBJECTS)
	@echo $(Y)Compiling [$(CFILES)]...$(X)
	@echo $(G)Finished [$(CFILES)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)

clean:
	@rm -f $(OBJECTS)
	@echo $(R)Removed [$(OBJECTS)]$(X)

fclean: clean
	@rm -f $(NAME)
	@echo $(R)Removed [$(NAME)]$(X)

re: fclean all

norm:
	norminette $(CFILES) includes/*.h

VALGRIND_ARGS = --leak-check=full --show-leak-kinds=all

valgrind: $(NAME)
	valgrind $(VALGRIND_ARGS) ./$(NAME) $(ARGS)

.PHONY: all clean fclean re valgrind
