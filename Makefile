CC=gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f 
SRCS = main.c push_swap.c push_swap_moves.c push_swap_radix.c push_swap_utils.c
LIBS = -L ./libft -l ft
OBJS = $(SRCS:.c=.o)
NAME = push_swap
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a


all: ${NAME}

$(LIBFT):
	$(MAKE) -C ./libft
	$(MAKE) -C ./libft bonus

$(PRINTF):
	$(MAKE) -C ./ft_printf

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	${CC} ${CFLAGS} ${OBJS} ${LIBS} ${PRINTF} -o ${NAME} 
.PHONY: clean fclean all re
clean:
	-${RM} ${OBJS}
	$(MAKE) -C ./libft clean
fclean: clean
	${RM} ${NAME}
	$(MAKE) -C ./libft fclean

re: fclean all