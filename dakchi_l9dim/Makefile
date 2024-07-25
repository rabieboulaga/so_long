NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror # -lmlx -lX11 -lXext -lm # -fsanitize=address
SRC = parsing.c\
	main.c\
	get_next_line.c\
	get_next_line_utils.c\
	utils_parsing.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o so_long

%.o : %.c
	$(CC) ${CFLAGS} -c  $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY :
