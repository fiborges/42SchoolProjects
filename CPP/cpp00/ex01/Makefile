BLACK = \033[1;30m
REDBG = \033[30;41m
RED = \033[0;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m

NAME			=	phonebook

SRC_DIR		=	./src/
OBJ_DIR		=	obj/

INCS_DIR	=	includes
MAIN_INC	= -I $(INCS_DIR)
INCS		=	$(shell find $(INCS_DIR) -type f -name "*.hpp")

SRC			=	main.cpp \
				PhoneBook.cpp \
				Contact.cpp
				
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC				=	clang++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "${BLUE} Creating ${SOFT_NAME} ${BLUE}${ORANGE}"
	$(CC) ${CFLAGS}  $(MAIN_INC) -o $@ -c $<
	@echo "${NC}"

$(NAME)		:	$(OBJ) $(INCS)
	@echo "${BLUE} Creating ${SOFT_NAME} ${BLUE}${ORANGE}"
	$(CC) $(CFLAGS) $(OBJ) $(MAIN_INC) -o $(NAME)
	@echo "${NC}"
					
all			:	$(NAME)

clean		:
	@echo "${RED} Cleaning .o files ${RED}"
	@rm -rf $(OBJ_DIR)
	@echo "${GREEN} Cleaning done ${GREEN}${NC}\n"

fclean		:	clean
	@echo "${RED} Cleaning archives and executables ${RED}"
	@rm -rf $(NAME)
	@echo "${GREEN} Cleaning done ${GREEN}${NC}\n"

re			:	fclean	all

.PHONY		:	all clean fclean re