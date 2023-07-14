# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguarien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 19:19:16 by sguarien          #+#    #+#              #
#    Updated: 2023/05/04 19:19:22 by sguarien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= so_long

PRINTF				= ./printf/libftprintf.a
PRINTFDIR			= ./printf
MINILIBXPATH		= ./mlx
MINILIBX			= $(MINILIBXPATH)/libmlx.a

SRC 				= ./src
SRCFUNCT			= main.c start_map.c map_size_validation.c  get_maps.c start_validations.c \
						game_validations.c render_img.c path_validation.c end_game.c \
						game_moves.c

OBJ 				= $(SRCFUNCT:%.c=%.o)

CC					= cc
AR					= ar rcs
RM					= rm -rf
CFLAGS				= -Wall -Wextra -Werror -g
MLXFLAGS			= -L ./mlx -lmlx -Ilmlx -lXext -lX11

MSG1				= @echo "Minilibx compiled"
MSG2				= @echo "./so_long Created"
MSG3				= @echo "Cleaning complete - objects files deleted"
MSG4				= @echo "ReCompilation complete - .a files deleted"



all:				$(NAME)

$(NAME):			$(OBJ)
						$(MAKE) -C $(MINILIBXPATH)
						$(MSG1) 
						$(MAKE) -C $(PRINTFDIR)
			 			$(CC) $(CFLAGS) -lm $(OBJ) $(MLXFLAGS) $(PRINTF) -o $(NAME)
						$(MSG2)

%.o:				$(SRC)/%.c
						@$(CC) $(CFLAGS) -c $< -o $@

clean:
						$(MAKE) clean -C $(PRINTFDIR)
						$(RM) $(OBJ)
						$(MSG3)

fclean:				clean
						$(RM) $(NAME)
						$(MSG4)

re:					fclean all

.PHONY: all clean fclean re