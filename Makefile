HEADER = ft_printf.h

SRC = ft_printf.c ft_putnbr_fd.c ft_putnbr_u_fd.c pointer.c utils.c\

NAME = libftprintf.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY : all clean fclean re
