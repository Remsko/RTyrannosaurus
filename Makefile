NAME = rt
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I./incs
LIBFT = libft/libft.a
LIBJSON = libjson/libjson.a

SRC_PATH = srcs/
SRC_NAME =	main.c \
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
			vector/vector_rotate.c \
			parser/parser_file.c \
			parser/parser_scene.c \
			parser/parser_camera.c \
			parser/parser_config.c \
			parser/parser_vector.c \
			parser/parser_double.c \
			parser/value_to_double.c \
			parser/value_exist.c \
			parser/nerf_double.c \
			parser/nerf_rotation.c \
			parser/nerf_color.c \
			parser/parser_lights.c \
			parser/parser_light_type.c \
			parser/parser_light_spec.c \
			parser/parser_point.c \
			parser/parser_directional.c \
			parser/parser_parallel.c \
			parser/parser_objects.c \
			parser/parser_object_type.c \
			parser/parser_object_spec.c \
			parser/parser_sphere.c \
			parser/parser_plane.c \
			parser/parser_cylinder.c \
			parser/parser_cone.c \
			#object/cone.c \
			object/cylinder.c \
			object/get_inter.c \
			object/get_normal.c \
			object/plan.c \
			object/solver_quadratic.c \
			object/sphere.c \

#SRC_NAME += 
#			sdl/sdl_destroy.c \
			sdl/sdl_init.c \
			sdl/sdl_loop.c \
			sdl/sdl_draw.c \
			sdl/sdl_event.c \

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

CPPFLAGS = -I./incs \
			-I./libft \
			-I./libjson/incs \
			-I ~/.brew/include/SDL2 \

LDFLAGS = -Llibft \
			-L./libjson/ \
			-L ~/.brew/lib \

LDLIBS = -lft -lSDL2 -lm -ljson

all: $(NAME)

$(LIBFT):
	make -C libft

$(LIBJSON):
	make -C libjson

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
	mkdir -p $(OBJ_PATH)vector
	mkdir -p $(OBJ_PATH)color
	mkdir -p $(OBJ_PATH)sdl
	mkdir -p $(OBJ_PATH)parser
	mkdir -p $(OBJ_PATH)object

$(NAME): $(LIBFT) $(LIBJSON) $(OBJ_PATH) $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS)  -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	make clean -C libft
	make clean -C libjson
	$(RM) $(OBJ)
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(LIBJSON)
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
