CC = cc

FLAG = -Wall -Werror -Wextra -g3

CLIENT = client

SERVER = server

SOURCES = utils.c client.c server.c

OBJ = $(SOURCES:.c=.o)

all : $(CLIENT) $(SERVER) $(OBJ)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(CLIENT): client.o utils.o
	$(CC) $^ -o $@

$(SERVER): server.o utils.o
	$(CC) $^ -o $@

%.o : %.c
	$(CC) $(FLAG) -c $< -o $@

clean :
	rm -f $(OBJ)
	
fclean : clean
	rm -f $(NAME)

re : fclean all