CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
NAME = so_long
SRCS = check_map.c checkers.c ft_parsing.c ft_split.c get_next_line.c get_next_line_utils.c image_moves_else.c main.c mooore.c moves.c textures.c
OBJS = $(SRCS:.c=.o)
INC = get_next_line.h so_long.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) 

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
