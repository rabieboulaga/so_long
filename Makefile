NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror # -fsanitize=address
SRC = parsing.c\
	main.c\
	get_next_line.c\
	get_next_line_utils.c\
	utils_parsing.c\
	check_map.c\
	check_tracks.c\
	display_map.c\
	player_movements.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o so_long

%.o : %.c
	$(CC) ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c  $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY :
