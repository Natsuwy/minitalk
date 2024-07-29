CC = cc

FLAG = -Wall -Werror -Wextra -g3

CLIENT = client

INCLUDES = -I . -I ft_printf/libft -I ft_printf

SERVER = server

SOURCES = utils.c client.c server.c

OBJ = $(SOURCES:.c=.o)

LIB = ft_printf/libft.a
LIB_INCLUDE = -Lft_printf -lft

all : $(LIB) $(CLIENT) $(SERVER) $(OBJ)

$(LIB)	:
	make -C ft_printf

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(INCLUDES) $(LIB_INCLUDE)

$(CLIENT): client.o utils.o 
	$(CC) $^ -o $@ $(INCLUDES) $(LIB_INCLUDE)

$(SERVER): server.o utils.o
	$(CC) $^ -o $@ $(INCLUDES) $(LIB_INCLUDE)

%.o : %.c
	$(CC) $(FLAG) -c $< -o $@ $(INCLUDES)

clean :
	rm -f $(OBJ)
	
fclean : clean
	rm -f $(NAME) $(CLIENT) $(SERVER)

re : fclean all
