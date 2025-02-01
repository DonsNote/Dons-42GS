/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:19:10 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/02/01 21:20:10 by dohyuki2         ###   ########.fr       */
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
# include "./Utilities/libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"

typedef enum e_img_type
{
	NO,
	SO,
	WE,
	EA
}	t_img_type;

typedef struct s_asset
{
	void		*img;
	t_img_type	type;
}	t_asset;

/* Parse */
int	check_map(int map);

/* Error */
int	error_print(int error);

#endif
