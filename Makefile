# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 21:15:08 by rpinoit           #+#    #+#              #
#    Updated: 2019/02/01 11:05:00 by rpinoit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt
RM = rm -rf

#==============================================================================#
#------------------------------------------------------------------------------#
#                                  HEADERS                                     #

INC_PATH += ./incs

INC_NAME += camera.h
INC_NAME += color.h
INC_NAME += intersection.h
INC_NAME += light.h
INC_NAME += object.h
INC_NAME += parser.h
INC_NAME += ray.h
INC_NAME += scene.h
INC_NAME += solver.h
INC_NAME += utils.h
INC_NAME += vector.h
INC_NAME += visu.h
INC_NAME += tracer.h

INC = $(addprefix $(INC_PATH)/, $(INC_NAME))

#==============================================================================#
#------------------------------------------------------------------------------#
#                            COMPILER & FLAGS                                  #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = $(addprefix -I, $(INC_PATH))

#==============================================================================#
#------------------------------------------------------------------------------#
#                                  SOURCES                                     #

SRC_PATH = ./srcs/
SRC_NAME += main.c

SRC_SUB += color
SRC_NAME += color_add.c
SRC_NAME += color_divide.c
SRC_NAME += color_multiply.c
SRC_NAME += color_to_max.c
SRC_NAME += color_to_range.c

SRC_SUB += hit
SRC_NAME += hit.c
SRC_NAME += intersection_cone.c
SRC_NAME += intersection_cylinder.c
SRC_NAME += intersection_plane.c
SRC_NAME += intersection_spec.c
SRC_NAME += intersection_sphere.c

#SRC_SUB += object
#SRC_NAME += cone.c
#SRC_NAME += cylinder.c
#SRC_NAME += get_normal.c
#SRC_NAME += plan.c
#SRC_NAME += solver_quadratic.c
#SRC_NAME += sphere.c

SRC_SUB += parser
SRC_NAME += parser_camera.c
SRC_NAME += parser_config.c
SRC_NAME += parser_double.c
SRC_NAME += parser_file.c
SRC_NAME += parser_scene.c
SRC_NAME += parser_vector.c
SRC_NAME += parser_color.c
SRC_NAME += parser_material.c

SRC_SUB += parser/lights
SRC_NAME += parser_directional.c
SRC_NAME += parser_lights.c
SRC_NAME += parser_light_spec.c
SRC_NAME += parser_light_type.c
SRC_NAME += parser_parallel.c
SRC_NAME += parser_point.c

SRC_SUB += parser/objects
SRC_NAME += parser_cone.c
SRC_NAME += parser_cylinder.c
SRC_NAME += parser_objects.c
SRC_NAME += parser_object_spec.c
SRC_NAME += parser_object_type.c
SRC_NAME += parser_plane.c
SRC_NAME += parser_sphere.c

SRC_SUB += parser/utils
SRC_NAME += nerf_color.c
SRC_NAME += nerf_double.c
SRC_NAME += nerf_rotation.c
SRC_NAME += value_exist.c

SRC_SUB += sdl
SRC_NAME += sdl_destroy.c
SRC_NAME += sdl_draw.c
SRC_NAME += sdl_event.c
SRC_NAME += sdl_init.c
SRC_NAME += sdl_loop.c

SRC_SUB += solver
SRC_NAME += solver_quadratic.c

SRC_SUB += tracer
SRC_NAME += raytracer.c
SRC_NAME += throw_ray.c

SRC_SUB += vector
SRC_NAME += vector_add.c
SRC_NAME += vector_divide.c
SRC_NAME += vector_dot_product.c
SRC_NAME += vector_magnitude.c
SRC_NAME += vector_multiply.c
SRC_NAME += vector_normalize.c
SRC_NAME += vector_rotate.c
SRC_NAME += vector_sub.c

vpath %.c $(SRC_PATH) $(addprefix $(SRC_PATH)/, $(SRC_SUB))

#==============================================================================#
#------------------------------------------------------------------------------#
#                                  OBJECTS                                     #

OBJ_PATH = ./.obj
OBJ_NAME = $(SRC_NAME:%.c=%.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME)) 

#==============================================================================#
#------------------------------------------------------------------------------#
#                                LIBRARIES                                     #

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
CPPFLAGS += -I$(LIBFT_PATH)#/incs
LDFLAGS += -L$(LIBFT_PATH) -lft


LIBJSON_PATH = ./libjson
LIBJSON = $(LIBJSON_PATH)/libjson.a
CPPFLAGS += -I$(LIBJSON_PATH)/incs
LDFLAGS += -L$(LIBJSON_PATH) -ljson

CPPFLAGS += `sdl2-config --cflags`
LDFLAGS += `sdl2-config --libs`

LDFLAGS += -lm

#==============================================================================#
#------------------------------------------------------------------------------#
#                                 RULES                                        #

NB = $(words $(SRC_NAME))
INDEX = 0

all: $(NAME)


$(NAME): $(OBJ) $(LIBFT) $(LIBJSON)
	@$(CC) -o $@ $^ $(LDFLAGS)
	@printf '\033[33m[ READY ] %s\n\033[0m' "Compilation of $(NAME) is done ---"

$(OBJ): $(INC) | $(OBJ_PATH)
$(OBJ): $(OBJ_PATH)/%.o: %.c
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval TO_DO=$(shell echo "$@"))
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@printf "[ %d%% ] %s :: %s        \r" $(PERCENT) $(NAME) $@
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

$(OBJ_PATH):
	@mkdir -p $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(LIBJSON):
	@$(MAKE) -C $(LIBJSON_PATH)

clean:
	@$(RM) $(OBJ_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(LIBJSON_PATH) clean
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Clean of $(NAME) is done ---"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@$(RM) $(LIBJSON)
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Fclean of $(NAME) is done ---"

re: fclean all

.PHONY: all clean fclean re
