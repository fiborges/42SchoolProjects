NAME		= phonebook

SRC_DIR		= ./src/
OBJ_DIR		= obj/

INCS_DIR	= includes
MAIN_INC	= -I $(INCS_DIR)
INCS		= $(shell find $(INCS_DIR) -type f -name "*.hpp")

SRC			= main.cpp \
			  PhoneBook.cpp \
			  Contact.cpp

OBJ			= $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

# Cores para mensagens
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) $(MAIN_INC) -o $@ -c $<

$(NAME): $(OBJ) $(INCS)
	@$(CC) $(CFLAGS) $(OBJ) $(MAIN_INC) -o $(NAME)
	@echo "$(GREEN)$(NAME) has been created successfully!$(RESET)"

all: $(NAME)

clean:
	@echo "$(RED)Cleaning object files$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Cleaning executable $(NAME)$(RESET)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
