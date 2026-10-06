NAME = so_long
FILES = so_long.c sl_map_check.c sl_map_read.c sl_utils.c valid_path.c sl_map_draw.c sl_image_load.c
EXC = so_long
OBJS = $(FILES:.c=.o)
CC = cc	
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	(cd libft && make)
	(cd ft_printf && make)
	(cd minilibx && make)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a ft_printf/libftprintf.a -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(EXC)

clean:
	(cd libft && make clean)
	(cd ft_printf && make clean)
	(cd minilibx && make clean)
	rm -f $(OBJS)

fclean: clean
	(cd libft && make fclean)
	(cd ft_printf && make fclean)
	rm -f $(EXC)

re: fclean all

.PHONY: all clean fclean re $(NAME)
