# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: Tessa <Tessa@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/11 14:02:46 by Tessa         #+#    #+#                  #
#    Updated: 2022/03/15 14:53:38 by tvan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

GREEN = 	\033[38;5;2m
NORMAL = 	\033[38;5;255m
RED = 		\033[38;5;1m

NAME =      	fractol	
VPATH = ./src ./src_bonus

SRCS =      	color.c \
				window.c \
				fractal.c \
				read_input.c \
				key_hook.c \
				mouse_hook.c \
				utils.c \
				main.c

BONUS =			color_bonus.c \
				window_bonus.c \
				fractal_bonus.c \
				read_input_bonus.c \
				key_hook_bonus.c \
				mouse_hook_bonus.c \
				utils_bonus.c \
				main_bonus.c

OFILES =    $(SRCS:.c=.o)
BFILES =	$(BONUS:.c=.o)

HEADER =  	./libft \
            ./mlx

CC = 		gcc
RM = 		rm -f
CFLAGS = 	-Wall -Wextra -Werror
MLXFLAGS = 	-framework OpenGl -framework AppKit -mtune=native -march=native -Ofast

ifdef WITH_BONUS
OBJS = $(BFILES)
else
OBJS = $(OFILES)
endif

all:        $(NAME)

$(NAME):	$(OBJS) $(HEADER)
			make -C libft/
			cp libft/libft.a .
			make -C mlx/
			cp mlx/libmlx.a .
			$(CC) -Lmlx -lmlx -Llibft -lft -o $(NAME) $(OBJS) $(CFLAGS) $(MLXFLAGS)
			@echo "$(GREEN)Successfully compiled!$(NORMAL)"

%.o:        %.c
			@echo "$(GREEN)Compiling:$(NORMAL)"
			$(CC) -Ilibft -Imlx -c $< -o $@ $(CFLAGS)
			
bonus:
			rm -f $(OFILES)
			$(MAKE) WITH_BONUS=1 all

clean:
			@echo "$(RED)Removing all object files...$(NORMAL)"
			$(RM) $(OFILES) $(BFILES)
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

.PHONY: 	all clean fclean re bonus





