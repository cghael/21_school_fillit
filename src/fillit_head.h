/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_head.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:12:28 by cghael            #+#    #+#             */
/*   Updated: 2019/11/08 14:50:36 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_HEAD_H
# define FILLIT_HEAD_H
# define BUFFSIZE 21
# define SEPARATE 1
# define USAGE "usage: ./fillit target_file\n"

# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

typedef struct			s_dest
{
	char				name;
	struct s_dest		*head;
	struct s_dest		*left;
	struct s_dest		*right;
	struct s_dest		*up;
	struct s_dest		*down;
	int					x;
	int					y;
	int					line;
}						t_dest;

typedef struct			s_tet
{
	char				name;
	int					x[4];
	int					y[4];
	struct s_tet		*next;
}						t_tet;

typedef struct			s_cwr
{
	t_list				*head;
	struct s_cwr		*right;
}						t_cwr;

t_tet					*ft_read_tetrimino(int fd);
int						ft_full_check_tetr(int res, char *buf);
t_dest					*ft_create_tdest(char name, int x, int y);
void					ft_delete_tet_list(t_tet *begin_list);
void					ft_delete_dest_list(t_dest **root);
t_dest					*ft_create_column_list(int n, t_dest *begin);
t_dest					*ft_create_dlist(t_tet *tetr, int n);
void					ft_uncover(t_list *queue);
int						ft_cover_all(t_list **queue, t_dest *goal);
int						ft_check_argc(int argc);
void					ft_print_tetris(t_dest *map, int n);
t_cwr					*ft_add_to_stack(t_cwr **stack, t_list *new);
int						ft_find_sqr_side(t_tet *tetr);
void					ft_uncover_and_free(t_cwr **stack, int i);
void					ft_delete_dest_row(t_dest *head);
t_dest					*ft_tetramino_to_map(t_dest *begin, t_tet *tetmap);
int						ft_find_smallest_sqr(t_tet *tetr, int n, t_dest **root);

#endif
