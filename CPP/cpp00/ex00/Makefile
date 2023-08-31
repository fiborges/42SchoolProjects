BLACK = \033[1;30m
REDBG = \033[30;41m
RED = \033[0;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m

CC := c++
FLAGS := -std=c++98 -Wall -Wextra -Werror -MMD -MP -Isources/
SRC_DIR := sources/
OBJ_DIR := objects/
RM := rm
VAL := valgrind --leak-check=full --track-origins=yes

BASE = megaphone \

SRCS = $(BASE:%=%.cpp)

SOFT_NAME := megaphone
OBJS = $(SRCS:%.cpp=%.o)
OBJ = $(addprefix $(OBJ_DIR),$(OBJS))
DEP = $(OBJ:%.o=%.d)
OBJF := ${OBJ_DIR}.cache_exists
NORM := $(wildcard *.cpp) $(wildcard *.hpp)

all : $(OBJF) ${SOFT_NAME}

${OBJ_DIR}%.o : %.cpp Makefile
	@echo "${BLUE}$ Creating file ${@:%.cpp=%.o}${BLUE}${ORANGE}"
	${CC} ${FLAGS} -c $< -o $@
	@echo "${NC}"

$(OBJF) :
	@mkdir -p ${OBJ_DIR}
	@touch ${OBJF}

${SOFT_NAME} : ${OBJ}
	@echo "${BLUE}$ Creating file ${SOFT_NAME}${BLUE}${ORANGE}"
	${CC} ${OBJ} ${FLAGS} -o ${SOFT_NAME}
	@echo "${NC}"

-include ${DEP}

test : all
	$(VAL) ./${SOFT_NAME} "shhhhh... I think the students are asleep..."

test1 : all
	$(VAL) ./${SOFT_NAME} Damnit " ! " "Sorry students, I thought this thing was off."

test2 : all
	$(VAL) ./${SOFT_NAME}

clean :
	@echo "${RED}$Cleaning .o files${RED}"
	${RM} -rf ${OBJ_DIR} ${OBJF}
	@echo "${GREEN}$ Cleanead ${GREEN}${NC}\n"

fclean : clean
	@echo "${RED}$ Cleaning archives and executables ${RED}"
	${RM} -f ${SOFT_NAME}
	@echo "${GREEN}$ ALL CLEANED ${GREEN}${NC}\n"

re : fclean all

.PHONY : all clean fclean re test test1 test2
