NAME = libftprintf.a

CMD = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
       ft_helper.c \
       ft_putnbr_base.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@cp $(LIBFT) $(NAME)              # Copy libft.a to libftprintf.a
	@ar rcs $(NAME) $(OBJS)           # Add project object files

%.o: %.c
	$(CMD) $(CFLAGS) -c $< -o $@      # Compile .c files into .o

clean:
	@rm -f $(OBJS)                    # Remove project object files

fclean: clean
	@rm -f $(NAME)                    # Remove libftprintf.a

re: fclean all

test: all
	$(CMD) test.c libftprintf.a $(LIBFT) -o test

.PHONY: all clean fclean re test
