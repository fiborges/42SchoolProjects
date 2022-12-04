NAME		=	server
BNAME		= 	client

SRCS		=	server.c \
				client.c
							
OBJS		= 	${SRCS:%.c=%.o}
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

LIBFT		=	./libft/libft.a
LIBFT_D		=	./libft/

RM			= 	rm -f

all: 		$(NAME) $(BNAME)


$(NAME):	$(LIBFT) server.o
			$(CC) $(CFLAGS) -o $(NAME) server.o -L $(LIBFT_D) -l ft

$(BNAME):	$(LIBFT) client.o
			$(CC) $(CFLAGS) -o $(BNAME) client.o -L $(LIBFT_D) -l ft


%.o: %.c
	$(CC) $(CFLAGS) -I minitalk.h -I $(LIBFT_D)libft.h -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_D)
	
clean:
		$(RM) -f $(OBJS)
		make clean -C $(LIBFT_D)

fclean:		clean
			$(RM) $(NAME) $(BNAME)
			make fclean -C $(LIBFT_D)

re:	fclean	all

.PHONY:	all clean fclean re