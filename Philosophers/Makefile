NAME = philo
FLAGS = -Wall -Wextra -Werror -pthread
PATH_OBJ = ./objects/

SRC = actions.c main.c utils.c utils2.c initialization.c end_condition.c fork_management.c

OBJ = ${SRC:%.c=$(PATH_OBJ)%.o}

TARGET = philo

all:		$(NAME)

$(NAME):	$(OBJ)
	cc $(FLAGS) $(OBJ) -o $(NAME)

$(PATH_OBJ)%.o: %.c
	@mkdir -p $(PATH_OBJ)
	cc $(FLAGS) -c $< -o $@ 
	@echo "\033[1;92m[SUCCESS] $@ Objects creation done!\033[0m"

clean:
	@rm -rf $(PATH_OBJ)
	@echo "\33[1;93m[SUCCESS] Objects removal done!\33[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;93m[SUCCESS] Removal done!\33[0m"

re: fclean all

.PHONY: all clean fclean re

tsan: clean $(OBJ)
	$(CC) $(CFLAGS) -fsanitize=thread $(OBJ) -o $(TARGET)
	./$(TARGET) $(ARGS)

valgrind: clean $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -pthread -o $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(NAME) $(ARGS)


# make tsan ARGS="5 800 200 200"                                                
# make valgrind ARGS="5 800 200 200" 