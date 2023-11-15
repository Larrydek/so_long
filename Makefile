NAME = so_long

SRC = so_long.c read.c put_map.c moves.c check_map.c flood_fill.c utils.c

OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
#CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -g3 -fsanitize=address


LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

GNL_DIR = ./GNL
GNL = $(GNL_DIR)/get_next_line.a

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(GNL):
	make -C $(GNL_DIR)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(GNL)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) \
	-L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -L$(GNL_DIR) -lget_next_line -o $(NAME)

%.o: %.c ./Libft/libft.h ./printf/libftprintf.h ./GNL/get_next_line.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	make clean -C $(GNL_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(GNL_DIR)


re: fclean all