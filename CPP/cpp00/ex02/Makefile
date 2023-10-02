NAME			= tests

SRC_DIR			= .
OBJ_DIR			= obj/
INCS_DIR		= .

MAIN_INC		= -I$(INCS_DIR)

INCS			= $(shell find $(INCS_DIR) -type f -name "*.hpp")

SRC				= tests.cpp \
				  Account.cpp

OBJ				= $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC				= clang++
CFLAGS			= -Wall -Wextra -Werror -std=c++98

$(shell mkdir -p $(OBJ_DIR) >/dev/null)

$(OBJ_DIR)%.o: %.cpp
	@echo "\033[1;32mCompiling\033[0m $<..."
	$(CC) $(CFLAGS) $(MAIN_INC) -o $@ -c $<

$(NAME): $(OBJ) $(INCS)
	$(CC) $(CFLAGS) $(OBJ) $(MAIN_INC) -o $(NAME)
	@echo "\033[1;36m$(NAME) compiled successfully!\033[0m"


all: $(NAME)


clean:
	@echo "\033[1;31mCleaning object files...\033[0m"
	@rm -rf $(OBJ_DIR)


fclean: clean
	@echo "\033[1;31mCleaning everything...\033[0m"
	@rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re
