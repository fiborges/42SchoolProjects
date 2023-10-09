NAME        = Zombie


SRC_DIR     = ./src/
OBJ_DIR     = obj/


SRC         = main.cpp


OBJ         = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))


CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98


GREEN       = \033[0;32m
RED         = \033[0;31m
RESET       = \033[0m


all         : $(NAME)


$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "$(GREEN)Compiled: $<$(RESET)"


$(NAME)     : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created.$(RESET)"


clean       :
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Object files removed.$(RESET)"


fclean      : clean
	@rm -f $(NAME)
	@echo "$(RED)Executable $(NAME) removed.$(RESET)"

re          : fclean all

.PHONY      : all clean fclean re
