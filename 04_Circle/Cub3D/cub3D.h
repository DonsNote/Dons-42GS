/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:19:10 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/27 02:39:34 by dohyuki2         ###   ########.fr       */
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

# define MINI_POS 25
# define MINI_SIZE 250
# define BORDER 5
# define CUB 8
# define CENTER 14

# define B 0x00000000
# define G 0x00555555
# define W 0x00FFFFFF
# define Y 0x00FFFF00
# define R 0x00FF0000
# define GR 0x00009900
# define BU 0x003333FF

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

typedef struct s_lists
{
	t_node		*head;
	t_node		*tail;
	int			size;
}	t_lists;

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
void		error_handle(t_error_type type);
void		line_error_handle(t_src *src, char **str, char **str1);
void		texture_error_handle(t_src *src);
void		valid_error_handle(t_src *src, t_lists *lists, t_stack *stack);

/* Parse */
t_src		*check_init(char *av);
t_lists		*init_list(void);
t_stack		*init_stack(void);
_Bool		is_color(char *arg);
int			get_color(t_src *src, char **color_data);
int			count_commas(char *str);
void		free_split(char **str);
void		inter_line(t_src *src, char **str);
void		push_back(t_lists *lists, t_data data);
void		push_front(t_lists *lists, t_data data);
void		pop_back(t_lists *lists);
void		pop_front(t_lists *lists);
t_data		get_front(t_lists *lists);
void		set_map(t_src *new, t_lists *lists);
void		check_valid(t_src *src, char c, t_vector pos);
void		free_list(t_lists **lists);
void		push(t_stack *stack, t_vector data);
t_vector	pop(t_stack *stack);
void		free_stack(t_stack **stack);
void		check_texture(t_src *src);
void		dfs(t_src *src, t_vector pos, t_stack *stack);
void		check_invalid(t_src *src, t_vector next_pos, t_stack *stack);
void		check_surround(t_src *src);

/* input */
int			input_key(int key, t_src *src);
void		rotate(int key, t_src *src);
void		move(int key, t_src *src);
int			input_exit(t_src *src);
t_vector	r_matrix(t_vector vec, float radian);
float		to_radian(float degree);
t_vector	get_move(int key, t_src *src, t_vector r_dir);
_Bool		is_collid(int key, t_src *src, t_vector r_dir, t_vector m_dir);
t_vector	get_player_side(int key, t_src *src, t_vector r_dir, int side);

/* draw */
t_draw		*init_canvas(int width, int height);
void		init_vector(t_src *src);
void		draw_pixel(t_draw *this, int w, int h, int color);
void		canvas_show(t_draw *this);
void		destroy_canvas(t_draw **this_ref);

int			draw(t_src *src);
void		drawing(t_src *src);
void		draw_line(t_src *src, t_dda *dda, int i);
t_drawing	init_drawing(t_src *src, t_dda *dda, t_texture *texture);
int			get_num(t_dda *dda);
int			get_pixel(t_texture *texture, int x, int y);
int			get_tex(t_src *src, t_dda *dda, t_texture *texture);
t_dda		*init_dda(t_src *src, t_vector ray);
void		step(t_dda *dda);
_Bool		is_collided(t_src *src, t_dda *dda);
t_dda		*raycasting(t_src *src, t_vector ray);
int			max(int a, int b);
int			min(int a, int b);

/* mini */
void		draw_background(t_src *src);
void		draw_minimap(t_src *src, t_vector start_pos);
int			set_color(t_src *src, t_vector cur);
void		big_draw(t_src *src, t_vector cur, t_vector start_pos, int color);
void		render_minimap(t_src *src);
int			check_file_name(char *file_name);
void		destroy_src(t_src *src);

#endif
