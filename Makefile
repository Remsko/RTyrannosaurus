NAME = rt
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I./incs
LIBFT = libft/libft.a

SRC_PATH = srcs/
SRC_NAME =	main.c \
			sdl/sdl_destroy.c \
			sdl/sdl_init.c \
			sdl/sdl_loop.c \
			sdl/sdl_draw.c \
			sdl/sdl_event.c \
			color/color_add.c \
			color/color_divide.c \
			color/color_multiply.c \
			color/color_to_max.c \
			color/color_to_range.c \
			vector/vector_add.c \
			vector/vector_multiply.c \
			vector/vector_divide.c \
			vector/vector_sub.c \
			vector/vector_dot_product.c \
			vector/vector_magnitude.c \
			vector/vector_normalize.c \

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

CPPFLAGS = -I./incs -I./libft  -I ~/.brew/include/SDL2
LDFLAGS = -Llibft -L ~/.brew/lib
LDLIBS = -lft -lSDL2 -lm

all: $(NAME)

$(LIBFT):
	make -C libft

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
	mkdir -p $(OBJ_PATH)vector
	mkdir -p $(OBJ_PATH)color
	mkdir -p $(OBJ_PATH)sdl

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
