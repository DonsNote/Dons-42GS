/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:18:43 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/02 16:47:54 by dohyuki2         ###   ########.fr       */
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

typedef struct	s_src
{
	void	*mlx;
	void	*win;
	void	*anya;
	void	*mama;
	void	*papa;
	void	*wall;
	void	*flow;
	int		*wid;
	int		*hei;
	char	**map;
}	t_src;



int		param_check(char *param);
int		map_size(int fd, t_src **src);
void	start_window(int map_h, int map_w);

#endif
