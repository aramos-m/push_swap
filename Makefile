NAME = push_swap

SRCS = src/main.c  src/push_swap_minor.c src/push_swap_major.c src/push_swap_moves.c src/push_swap_utils.c
LIBS = -L ./libft -l ft

OBJS = $(SRCS:.c=.o)

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g3
RM		= rm -f

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

clean:
	${RM} ${OBJS}
	$(MAKE) -C ./libft clean

fclean: clean
	${RM} ${NAME}
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: clean fclean all re