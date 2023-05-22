# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: Tessa <Tessa@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/11 14:02:46 by Tessa         #+#    #+#                  #
#    Updated: 2023/05/22 21:56:52 by Tessa         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

GREEN = 			\033[38;5;2m
NORMAL = 			\033[38;5;255m
RED = 				\033[38;5;1m

NAME =				fractol
VPATH =				./src
OBJS_DIR =			objs

SRCS =				color.c \
					window.c \
					fractal.c \
					read_input.c \
					key_hook.c \
					mouse_hook.c \
					utils.c \
					main.c

OBJS =    			$(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

HEADER =  			./libft \
            		./mlx

CC = 				gcc
RM = 				rm -rf
CFLAGS = 			-Wall -Wextra -Werror
MLXFLAGS = 			-framework OpenGl -framework AppKit -mtune=native -march=native -Ofast

all:        		$(NAME)

$(NAME):			$(OBJS) $(HEADER)
					make -C libft/
					cp libft/libft.a .
					make -C mlx/
					cp mlx/libmlx.a .
					$(CC) -Lmlx -lmlx -Llibft -lft -o $(NAME) $(OBJS) $(CFLAGS) $(MLXFLAGS)
					@echo "$(GREEN)Successfully compiled!$(NORMAL)"

$(OBJS_DIR)/%.o:	%.c | $(OBJS_DIR)
					@echo "$(GREEN)Compiling:$(NORMAL)"
					$(CC) -Ilibft -Imlx -c $< -o $@ $(CFLAGS)

$(OBJS_DIR):
					@mkdir -p $@

clean:
					@echo "$(RED)Removing all object files...$(NORMAL)"
					$(RM) $(OBJS_DIR)
					make clean -C libft/
					make clean -C mlx/
					@echo "$(GREEN)Succesfully removed all object files!$(NORMAL)"

fclean:				clean
					@echo "$(RED)Removing libraries...$(NORMAL)"
					$(RM) mlx/libmlx.a
					$(RM) libmlx.a
					$(RM) libft/libft.a
					$(RM) libft.a
					$(RM) $(NAME)
					@echo "$(GREEN)Successfully removed libraries!$(NORMAL)"

re:        			fclean all

.PHONY: 			all clean fclean re bonus





