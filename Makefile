NAME = libftprintf.a

CMD = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	ft_helper.c \
	ft_putnbr_base.c\
	ft_pointer.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CMD) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
