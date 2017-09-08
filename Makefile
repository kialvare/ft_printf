NAME = libftprintf.a

SRC_DIR = srcs/
LIB_DIR = libft/

SRC_FILES = base.c \
			ft_printf.c \
			get_data.c \
			print_char.c \
			print_nums.c
LIB_FILES = ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_strlen.c \
			ft_itoa.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
LIBFT = $(addprefix $(LIB_DIR), $(LIB_FILES))

OBJ = $(SRC_FILES:.c=.o) $(LIB_FILES:.c=.o)

INC = -Iincludes/
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec."
	@gcc -c $(FLAGS) $(SRC) $(LIBFT) $(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "(•̀ᴗ•́)و $(NAME) generated!".

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
