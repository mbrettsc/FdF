CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
RM = rm -f
NAME = fdf
LIBS = -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
SRCS = sources/convert.c sources/rotate.c sources/init.c sources/main.c sources/read_map.c sources/split.c sources/utils.c get_next_line/*.c printf/*.c sources/draw.c sources/color.c sources/draw_utils.c sources/push_pop.c sources/keyboard_controls.c sources/controls.c sources/controls_utils.c sources/mouse_controls.c sources/menu.c

${NAME}:
	${CC} ${CFLAGS} ${SRCS} ${LIBS} -o ${NAME}

all: ${NAME}

clean:

fclean: clean
	$(RM) ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re