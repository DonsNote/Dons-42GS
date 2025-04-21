/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:19:10 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/22 01:12:27 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <math.h>
# include <limits.h>
# include "./Utilities/libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"

# define WIDTH 1280
# define HEIGHT 720

# define FOV 0.66

# define NORTH 0
# define SOUTH 1
# define WEST  2
# define EAST  3

# define ELEMS 6
# define WALL_SIZE 4

typedef enum e_error_type
{
	e_allocate = 0,
	e_open = 1,
	e_read = 2,
	e_arg = 3,
	e_map = 4
}	t_error_type;

typedef struct s_check_map
{
	bool	no;
	bool	so;
	bool	we;
	bool	ea;
	int		where;
}	t_check_map;

typedef struct s_image
{
	void	*img;
	int		*data;
	int		bits_pixel;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_canvas
{
	void	(*draw_pixel)(struct s_canvas *this, int w, int h, int color);
	void	(*show)(struct s_canvas *this);

	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_image	img;
}	t_canvas;

typedef struct s_src
{
	t_texture	textures[WALL_SIZE];
	int			f_color;
	int			c_color;
	int			width;
	int			height;
	char		**map;
	int			frame_conut;
	t_vector	player;
	t_vector	dir;
	t_vector	plane;
	t_canvas	*canvas;
	float		**buffer[WIDTH];
}	t_src;

typedef struct s_texture
{
	void	*img;
	int		width;
	int		height;
	char	*path;
	char	*data;
	int		bits_pixel;
	int		size_line;
	int		endian;
}	t_texture;

typedef union u_data
{
	t_vector	vec;
	char		*str;
}	t_data;

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	t_data			data;
}	t_node;

typedef struct s_node2
{
	struct s_node2	*prev;
	struct s_node2	*next;
	t_vector		data;
}	t_node2;

typedef struct s_list
{
	t_node		*head;
	t_node		*tail;
	int			size;
}	t_list;

typedef struct s_stack
{
	t_node2	*top;
	int		size;
}	t_stack;

/* Utilities */
_Bool		is_color(char *arg);
int			get_color(char *color_data);
int			count_num_of_commas(char *str);
void		error_handle(t_error_type type);
void		free_split(char **str);
void		inter_line(t_src *src, char **str);
void		push_back(t_list *list, t_data data);
void		push_front(t_list *list, t_data data);
void		pop_back(t_list *list);
void		pop_front(t_list *list);
t_list		*init_list(void);
t_data		get_front(t_list *list);
void		check_valid(t_src *src, char c, t_vector pos);
void		free_list(t_list **list);
void		push(t_stack *stack, t_vector data);
t_vector	pop(t_stack *stack);
void		free_stack(t_stack **stack);
t_stack		*init_stack(void);
void		check_texture(t_src *src);

/* Parse */
t_src		*check_init(char *av);

#endif
