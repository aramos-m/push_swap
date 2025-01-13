NAME = libftprintf.a

SRC = ft_printf.c ft_printfutils.c

OBJS = $(SRC:.c=.o)

CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f 

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
