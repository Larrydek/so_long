NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit #-g3 -fsanitize=address
RM = rm -f
SRC = so_long.c read.c put_map.c moves.c check_map.c flood_fill.c

OBJ = $(SRC:.c=.o)


$(NAME) : $(OBJ)
	@${MAKE} -C ./Libft
	@${MAKE} -C ./GNL
	@${MAKE} -C ./printf
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) ./Libft/libft.a ./GNL/get_next_line.a  ./printf/libftprintf.a -o $(NAME)

all : $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	@${MAKE} -C ./Libft fclean
	@${MAKE} -C ./GNL fclean
	@${MAKE} -C ./printf fclean
	@$(RM) $(OBJ)
fclean: clean
	@$(RM) $(NAME)
re: fclean all