NAME = rt
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I./incs
LIBFT = libft/libft.a

SRC_PATH = srcs/
SRC_NAME =	main.c \
			sdl_init.c \
			sdl_destroy.c \
			sdl_loop.c \
			sdl_draw.c \
			sdl_event.c \
			sdl_fps.c \
			raytracer_core.c \
			raytracer_tracer.c \
			color_add.c \
			color_add_const.c \
			color_divide.c \
			color_divide_const.c \
			color_multiply.c \
			color_multiply_const.c \
			new_ray.c \

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

CPPFLAGS = -Iincs -Ilibft  -I ~/.brew/include/SDL2
LDFLAGS = -Llibft -L ~/.brew/lib
LDLIBS = -lft -lSDL2

all: $(NAME)

$(LIBFT):
	make -C libft

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(LIBLST) $(LIBFT) $(OBJ_PATH) $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS)  -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	make clean -C libft
	$(RM) $(OBJ)
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re