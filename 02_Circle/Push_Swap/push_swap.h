/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:34:23 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/30 17:23:10 by dohyuki2         ###   ########.fr       */
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
	int				arev;
	int				brev;
	int				atotop;
	int				btotop;
	int				total;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

int		check_param(int ac, char **av);
void	print_error(void);
int		*make_num_arr(int ac, char **av, int *size);
t_list	*make_stack(int *num, int size);
void	destroid_stack(t_list **a, int *asize);
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
void	hpush(t_list **a, t_list **b, int *asize, int *bsize);
void	make_ceed(t_list **a, int size);
int		checker(t_list **a, int size);
void	count_top_a(t_list **a, int size);
void	count_top_b(t_list **a, int size);
void	count_total(t_list **a, t_list **b, int *asize, int *bsize);
void	reset_cost(t_list **a, int size);
void	action(t_list **a, t_list **b, int *asize, int *bsize);
void	find_do(t_list **a, t_list **b, int *asize, int *bsize);
void	input_total(t_list **a, int size);
int		rank_bettle(t_list **a, t_list **b, int sol);
void	fix_total(t_list **a, t_list **b, int *asize, int j);

#endif