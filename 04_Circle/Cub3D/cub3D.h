/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:19:10 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/02/05 16:41:22 by dohyuki2         ###   ########.fr       */
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

typedef struct s_check_map
{
	bool	no;
	bool	so;
	bool	we;
	bool	ea;
}	t_check_map;

typedef enum e_direction
{
	NO = 0,
	SO,
	WE,
	EA
}	t_direcion;

typedef struct s_asset
{
	void	*no_texture;
	void	*so_texture;
	void	*we_texture;
	void	*ea_texture;
}	t_asset;

/* Parse */
int	check_map(int map);

/* Error */
int	error_print(int error);

#endif
