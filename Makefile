NAME = test

CMD = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = libft

SRCS = ft_printf.c\
		ft_putnbr_base.c\
		ft_helper.c\
		test.c

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

all: test

test:
	$(CMD) $(CFLAGS) -I$(INCLUDE) $(SRCS) -L $(LIBFT_DIR) -lft -o $(NAME)

clean:
	rm -rf test

re: clean all
