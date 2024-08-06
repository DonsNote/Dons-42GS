/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:18:43 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/08/06 14:15:30 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"

typedef struct s_src
{
	void	*mlx;
	void	*win;
	void	*anya;
	void	*mama;
	void	*fafa;
	void	*wall;
	void	*flow;
	int		wid;
	int		hei;
	int		food;
	int		count;
	char	**map;
}	t_src;

typedef struct s_check
{
	int	p_check;
	int	c_check;
	int	e_check;
}	t_check;

int		param_check(char *param);
int		map_size(t_src **src, char *av);
int		map_check(t_src **src);
char	**make_check_map(t_src **src);
void	scan_map(t_src **src, char **check);
int		bit_map(t_src **src, char **check);
void	start_window(t_src **src);
void	finish_window(t_src **src);
int		input_key(int key, void **src);
int		input_x(int key, void **src);
void	where_p(t_src **src, int *i, int *j);
void	move_w(t_src **src, int i, int j);
void	move_a(t_src **src, int i, int j);
void	move_s(t_src **src, int i, int j);
void	move_d(t_src **src, int i, int j);

#endif
