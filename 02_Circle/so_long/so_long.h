/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:18:43 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/03 05:42:28 by dohyuki2         ###   ########.fr       */
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

typedef struct s_src
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

typedef struct s_check
{
	int	w_check;
	int	p_check;
	int	c_check;
	int	e_check;
	int	f_check;
}	t_check;

int		param_check(char *param);
int		map_size(t_src **src, char *av);
void	start_window(t_src **src);

#endif
