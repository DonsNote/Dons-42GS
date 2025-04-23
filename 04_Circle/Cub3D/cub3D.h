/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:19:10 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/23 17:19:04 by dohyuki2         ###   ########.fr       */
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
# include "./input/input_code.h"
# include "./Utilities/libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"

# define TRUE 1
# define FALSE 0

# define WIDTH 1280
# define HEIGHT 720

# define FOV 0.66

# define NORTH 0
# define SOUTH 1
# define WEST  2
# define EAST  3

# define ELEMS 6
# define WALL_SIZE 4

# define ROTATE_DEGREE 2.f
# define MOVE_SPEED 0.1f
# define FAT 0.15f
# define RIGHT -1
# define LEFT 1

# define RENDER 10
# define OVERFLOW 0xFF000000

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

typedef struct s_draw
{
	void	(*draw_pixel)(struct s_draw *this, int w, int h, int color);
	void	(*show)(struct s_draw *this);

	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_image	img;
}	t_draw;

typedef struct s_drawing
{
	t_vector	t_pos;
	float		t_step;
	int			line_h;
	int			line_s;
	int			line_e;
	int			pos;
}	t_drawing;

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
	t_draw		*canvas;
	float		buffer[WIDTH];
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

typedef struct s_dda
{
	t_vector	cur;
	t_vector	dist;
	t_vector	inter;
	t_vector	step;
	t_vector	ray;
	float		w_dist;
	_Bool		hit;
	char		target;
}	t_dda;

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
void		dfs(t_src *src, t_vector pos, t_stack *stack);
void		check_invalid(t_src *src, t_vector next_pos);
void		check_surround(t_src *src);

/* Parse */
t_src		*check_init(char *av);

/* input */
int			input_key(int key, t_src *src);
void		rotate(int key, t_src *src);
void		move(int key, t_src *src);
int			m_move(int x, int y, t_src *src);
int			input_exit(void);
t_vector	r_matrix(t_vector vec, float radian);

/* draw */
int			draw(t_src *src);
void		drawing(t_src *src);
void		draw_line(t_src *src, t_dda *dda, int i);
t_drawing	init_drawing(t_src *src, t_dda *dda, t_texture *texture);
int			get_num(t_dda *dda);
int			get_pixel(t_texture *texture, int x, int y);
int			get_tex_x(t_src *src, t_dda *dda, t_texture *texture);

#endif
