/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:19:10 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/04/21 01:34:53 by dohyuki2         ###   ########.fr       */
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

typedef struct s_src
{
	void	*mlx;
	void	*win;
	void	*no_texture;
	void	*so_texture;
	void	*we_texture;
	void	*ea_texture;
	int		wid;
	int		hei;
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

/* Utilities */
void	error_handle(t_error_type type);

/* Parse */
int		jump_sp(char *str);
int		check_map(int map);

#endif
