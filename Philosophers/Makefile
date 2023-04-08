NAME			= philo

INCLUDE			= ./includes/
SRC_DIR			= ./src/

SRC_FILES		= philo.c utils.c states.c utils2.c dinner.c

SRCS			= $(addprefix $(SRC_DIR),$(SRC_FILES))
OBJS			= $(SRCS:.c=.o)

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

# Define some colors
RED				= \033[0;31m
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
BLUE			= \033[0;34m
PINK			= \033[0;35m
RESET			= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling $(NAME)$(RESET)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)Compilation complete!$(RESET)"

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	@echo "$(PINK)All cleaned up!$(RESET)"

re:	fclean all

.PHONY:	all clean fclean re

