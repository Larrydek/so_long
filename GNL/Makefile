NAME = libget_next_line.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = get_next_line.c \
		get_next_line_utils.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

all : $(NAME)

$(NAME) : $(OBJ)
		ar rcs $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)
fclean: clean
	@$(RM) $(NAME)
re: fclean all