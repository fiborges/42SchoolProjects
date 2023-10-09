# ANSI Colors
RESET	= \033[0m
BLACK	= \033[1;30m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
PURPLE	= \033[1;35m
CYAN	= \033[1;36m
WHITE	= \033[1;37m

# Compiler
CXX		= c++
RM		= rm -rf
AR		= ar -rcs

# Compilation Flags
CFLAGS	= -Wall -Wextra -Werror -pedantic -std=c++98

# Directories
DEPS	= .
SRCS	= .
_SUBFOLDERS	= 
VPATH	= $(SRCS) $(addprefix $(SRCS)/, $(_SUBFOLDERS))
OBJ_DIR	= obj

# Executable Name and Files
NAME	= Replace
_FILES	= main
OBJS	= $(_FILES:%=%.o)
TARGET	= $(addprefix $(OBJ_DIR)/, $(OBJS))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(TARGET)
	@echo "$(GREEN)[ Linking ] $(RESET)$(CYAN)*$(RESET)"
	$(CXX) $(CFLAGS) $(TARGET) -o $(NAME) -I $(DEPS)

$(OBJ_DIR)/%.o : %.cpp
	@echo "$(GREEN)[ Compiling ] $(CFLAGS)$(RESET) $(GREEN)$<$(RESET)"
	$(CXX) $(CFLAGS) -c $< -o $@ -I $(DEPS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	@echo "$(RED)[ Deleted ] $(RESET)$(GREEN)$(OBJ_DIR)$(RESET)"
	$(RM) $(OBJ_DIR)

fclean: clean
	@echo "$(RED)[ Deleted ] $(RESET)$(GREEN)$(NAME)$(RESET)"
	$(RM) $(NAME)

re: fclean all

run: re
	./$(NAME)