NAME = btc

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g3 -fsanitize=address

CC = c++

SRC_FILES = main.cpp \
			BitcoinExchange.cpp

OBJS = $(SRC_FILES:.cpp=.o)


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re