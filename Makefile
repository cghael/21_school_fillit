# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cghael <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 17:11:16 by cghael            #+#    #+#              #
#    Updated: 2019/11/08 17:20:48 by cghael           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c\
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

LIB = libft

O_FLS = $(SRC:.c=.o)

SRC_DIR = src

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

vpath %.c $(SRC_DIR)

all: $(NAME)

$(NAME): $(O_FLS)
		make -C $(LIB)
		gcc $(FLAGS) $(addprefix $(SRC_DIR)/, $^) -L$(LIB) -lft -I$(SRC_DIR) -I$(LIB) -o $(NAME)

%.o: %.c
		gcc -c $(FLAGS) -I$(LIB) $< -o $(addprefix $(SRC_DIR)/, $@)

clean:
		rm -f $(addprefix $(SRC_DIR)/, $(O_FLS))
		make -C $(LIB) clean

fclean: clean
		rm -f $(NAME)
		make -C $(LIB) fclean

re: fclean all
