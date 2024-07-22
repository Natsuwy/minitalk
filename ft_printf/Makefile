CC = cc

FLAGS = -Wall -Werror -Wextra

INCLUDE = -I . -I libft

NAME = libftprintf.a

SOURCES = ft_hex.c \
	ft_ptrhex.c id.c printftest.c

OBJ = $(SOURCES:.c=.o)

$(NAME) : $(OBJ)
	make bonus -C libft/
	cp libft/libft.a libftprintf.a
	ar -rcs $(NAME) ${OBJ}

%.o : %.c
	$(CC) $(FLAG) -c $< -o $@ $(INCLUDE)

all : $(NAME)

clean :
	make clean -C libft/
	rm -f $(OBJ) a.out

fclean : clean
	make fclean -C libft/
	rm -f $(NAME)

re : fclean all
	make re -C libft/

reload :
	make all
	#make clean
	cc -Wall -Wextra -Werror printftest.c libftprintf.a
	./a.out