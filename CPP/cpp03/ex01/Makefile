NAME        = ClapTrap

SRC_DIR     = ./src/
OBJ_DIR     = obj/
INCS_DIR    = ./includes


MAIN_INC    = -I $(INCS_DIR)


INCS        = $(shell find $(INCS_DIR) -type f -name "*.hpp")


SRC         = main.cpp \
              ClapTrap.cpp \
			  ScavTrap.cpp


OBJ         = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))


CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98


GREEN       = \033[0;32m
RED         = \033[0;31m
RESET       = \033[0m


all         : $(NAME)


$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INCS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(MAIN_INC) -o $@ -c $<
	@echo "$(GREEN)Compiled: $<$(RESET)"


$(NAME)     : $(OBJ) $(INCS)
	@$(CC) $(CFLAGS) $(OBJ) $(MAIN_INC) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created.$(RESET)"


clean       :
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Object files removed.$(RESET)"


fclean      : clean
	@rm -f $(NAME)
	@echo "$(RED)Executable $(NAME) removed.$(RESET)"

re          : fclean all

.PHONY      : all clean fclean re