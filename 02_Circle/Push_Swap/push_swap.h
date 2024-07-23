/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:34:23 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/23 14:53:32 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				num;
	int				rank;
	int				min;
	int				max;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

void	print_error(void);
int		check_param(int ac, char **av);
int		*make_num_arr(int ac, char **av, int *size);
t_list	*make_stack(int *num, int size);

#endif