NAME = libftprintf.a

CFILES = ft_helper.c

OFILES = $(CFILES:.c=.o)

INCLUDE = include

CMD = cc

FLAGS = -Werror -Wextra -Wall -I ${INCLUDE}

$(NAME) :
	${CMD} -c ${FLAGS} ${CFILES}
	ar rcs ${NAME} ${OFILES}

all : $(NAME)

clean :
	rm -rf *.o

fclean :
	rm -rf *.o ${NAME}

re:fclean all

.PHONY: all clean fclean re
