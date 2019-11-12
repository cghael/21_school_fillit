# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cghael <cghael@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 13:56:52 by cghael            #+#    #+#              #
#    Updated: 2019/11/12 15:43:14 by cghael           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LDFLAGS = -L./libft

LDLIBS = -lft

CPPIFLAGS = -I.

SRC_NAME = 	main.c \
		ft_read_tetrimino.c\
		ft_full_check_tetr.c\
		ft_check_argc.c\
		ft_create_tdest.c\
		ft_find_smallest_sqr.c\
		ft_delete_dest_list.c\
		ft_uncover_and_free.c\
		ft_delete_dest_row.c\
		ft_delete_tet_list.c\
		ft_create_column_list.c\
		ft_tetramino_to_map.c\
		ft_uncover.c\
		ft_find_sqr_side.c\
		ft_cover_all.c\
		ft_print_tetris.c\
		ft_add_to_stack.c\
		ft_create_dlist.c

OBJ = ./src/

SRC = ./src/

OBJ_NAME = $(SRC_NAME:.c=.o)

HEAD = ./

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_NAME)
	@make -C ./libft
	@$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -I $(HEAD) $(addprefix $(OBJ), $^) -o $@
	@echo "\033[0;32mfillit's program created.\033[0m"

%.o: $(SRC)%.c
	@$(CC) $(CFLAGS) -Ilibft -o $(OBJ)$@ -c $<

clean:
	@rm -rf $(addprefix $(OBJ), $(OBJ_NAME))
	@make -C ./libft clean
	@echo "\033[0;32mfillit's .o files deleted.\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C ./libft fclean
	@echo "\033[0;32mfillit Project fully cleaned.\033[0m"

re: fclean all
