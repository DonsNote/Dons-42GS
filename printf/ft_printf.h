/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:54:01 by kyouhele          #+#    #+#             */
/*   Updated: 2024/03/27 13:41:58 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define UPPER "0123456789ABCDEF"
# define LOWER "0123456789abcdef"

int		ft_printf(const char *arg, ...);
char	*ft_uitoa(unsigned int n);
size_t	ft_putnbr_base(unsigned long int nbr, char type);
int		correct_type(char next);

#endif
