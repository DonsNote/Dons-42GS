/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:18:43 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/02 13:34:45 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"

# ifndef TILE_SIZE
#  define TILE_SIZE 32
# endif

typedef struct	s_imgsrc
{
	void	*anya;
	void	*mama;
	void	*papa;
	void	*wall;
	void	*flow;
}	t_imgsrc;



int		param_check(char *param);
void	start_window(int map_h, int map_w);

#endif
