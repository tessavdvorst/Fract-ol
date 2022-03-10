# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: Tessa <Tessa@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/11 14:02:46 by Tessa         #+#    #+#                  #
#    Updated: 2022/03/10 17:21:51 by tvan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

GREEN = 	\033[38;5;2m
NORMAL = 	\033[38;5;255m
RED = 		\033[38;5;1m

NAME =      fractol

SRCS =      ./src/color.c \
			./src/window.c \
			./src/fractal.c \
			./src/read_input.c \
			./src/key_hook.c \
			./src/mouse_hook.c \
			./src/utils.c \
			./src/main.c

OFILES =    $(SRCS:.c=.o)

INCLUDES =  ./libft \
            ./mlx

CC = 		gcc
RM = 		rm -f
CFLAGS = 	-Wall -Wextra -Werror
MLXFLAGS = 	-framework OpenGl -framework AppKit -mtune=native -march=native -Ofast

all:        $(NAME)

$(NAME):	$(OFILES) $(INCLUDES)
			make -C libft/
			cp libft/libft.a .
			make -C mlx/
			cp mlx/libmlx.a .
			$(CC) -Lmlx -lmlx -Llibft -lft -o $(NAME) $(OFILES) $(CFLAGS) $(MLXFLAGS)
			@echo "$(GREEN)Successfully compiled!$(NORMAL)"

%.o:        %.c
			@echo "$(GREEN)Compiling:$(NORMAL)"
			gcc -Ilibft -Imlx -c $< -o $@ $(CFLAGS)
			
clean:
			@echo "$(RED)Removing all object files...$(NORMAL)"
			$(RM) $(OFILES)
			make clean -C libft/
			make clean -C mlx/
			@echo "$(GREEN)Succesfully removed all object files!$(NORMAL)"

fclean:		clean
			@echo "$(RED)Removing libraries...$(NORMAL)"
			$(RM) mlx/libmlx.a
			$(RM) libmlx.a
			$(RM) libft/libft.a
			$(RM) libft.a
			$(RM) $(NAME)
			@echo "$(GREEN)Successfully removed libraries!$(NORMAL)"

re:        	fclean all

.PHONY: 	all clean fclean re





