/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:34:23 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/07/25 13:21:27 by dohyuki2         ###   ########.fr       */
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
	int				cost;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

int		check_param(int ac, char **av);
void	print_error(void);
int		*make_num_arr(int ac, char **av, int *size);
t_list	*make_stack(int *num, int size);
void	push_swap(t_list *a, t_list *b, int size);
t_list	*swap_a(t_list *a);
t_list	*swap_b(t_list *a);
t_list	*swap_s(t_list *a, t_list *b);
t_list	*rotate_a(t_list *a);
t_list	*rotate_b(t_list *a);
t_list	*rotate_r(t_list *a, t_list *b);
t_list	*reverse_a(t_list *a);
t_list	*reverse_b(t_list *a);
t_list	*reverse_r(t_list *a, t_list *b);
t_list	*push_a(t_list *a, t_list **b);
t_list	*push_b(t_list *a, t_list *b);

#endif