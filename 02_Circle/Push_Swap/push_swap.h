/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:34:23 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/28 14:56:48 by dohyuki2         ###   ########.fr       */
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
	int				totop;
	int				total;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

int		check_param(int ac, char **av);
void	print_error(void);
int		*make_num_arr(int ac, char **av, int *size);
t_list	*make_stack(int *num, int size);
void	destroid_stack(t_list **a);
void	push_swap(t_list *a, t_list *b, int size);
void	swap_a(t_list **a, int check);
void	swap_b(t_list **a, int check);
void	swap_s(t_list **a, t_list **b);
void	rotate_a(t_list **a);
void	rotate_b(t_list **a);
void	rotate_r(t_list **a, t_list **b);
void	reverse_a(t_list **a);
void	reverse_b(t_list **a);
void	reverse_r(t_list **a, t_list **b);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	lmpush(t_list **a, t_list **b, int *asize, int *bsize);
void	make_ceed(t_list **a, int size);
int		checker(t_list **a, int size);
void	count_top(t_list **a, int size);
void	count_total(t_list **a, t_list **b, int *asize);
void	reset_cost(t_list **a, int size);
void	action_a(t_list **a, int size);
void	action_b(t_list **a, int size);
void	go_atop(t_list **a, int size);
void	go_artop(t_list **a, int size);
void	go_btop(t_list **a, int size);
void	go_brtop(t_list **a, int size);
#endif