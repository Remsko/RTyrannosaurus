NAME = libft.a
CC = gcc
RM = rm -rf
CFLAGS = -c -Wall -Werror -Wextra
SRC =	ft_lstdel.c \
	ft_memmove.c \
	ft_strchr.c \
	ft_strlen.c \
	ft_strstr.c \
	ft_lstdelone.c \
	ft_memset.c \
	ft_strclr.c \
	ft_strmap.c \
	ft_strsub.c \
	ft_atoi.c \
	ft_lstiter.c \
	ft_putchar.c \
	ft_strcmp.c \
	ft_strmapi.c \
	ft_strtrim.c \
	ft_bzero.c \
	ft_lstmap.c \
	ft_putchar_fd.c \
	ft_strcpy.c \
	ft_strncat.c \
	ft_tolower.c \
	ft_isalnum.c \
	ft_lstnew.c \
	ft_putendl.c \
	ft_strdel.c \
	ft_strncmp.c \
	ft_toupper.c \
	ft_isalpha.c \
	ft_memalloc.c \
	ft_putendl_fd.c \
	ft_strdup.c \
	ft_strncpy.c \
	ft_isascii.c \
	ft_memccpy.c \
	ft_putnbr.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_isdigit.c \
	ft_memchr.c \
	ft_putnbr_fd.c \
	ft_striter.c \
	ft_strnew.c \
	ft_isprint.c \
	ft_memcmp.c \
	ft_putstr.c \
	ft_striteri.c \
	ft_strnstr.c \
	ft_itoa.c \
	ft_memcpy.c \
	ft_putstr_fd.c \
	ft_strjoin.c \
	ft_strrchr.c \
	ft_lstadd.c \
	ft_memdel.c \
	ft_strcat.c \
	ft_strlcat.c \
	ft_strsplit.c \
	ft_count_words.c \
	ft_atoi_base.c \
	ft_isspace.c \
	ft_print_words_tables.c \
	ft_itoa_base.c \
	ft_swap.c \
	ft_sqrt.c \
	ft_find_next_prime.c \
	ft_isnegative.c \
	get_next_line.c \
	ft_intmax.c \
	ft_intpow.c \
	ft_strndup.c \
	ft_deltab.c \
	ft_tablen.c \
	ft_lstrev.c \
	ft_isstrint.c \

OBJ_PATH = obj/
OBJ_NAME = $(SRC:.c=.o)
	OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME)) 

all: $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(NAME): $(OBJ_PATH) $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@echo $(NAME) ✔

$(OBJ_PATH)%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_PATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
