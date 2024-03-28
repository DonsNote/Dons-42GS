/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: don <don@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:40:45 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/03/29 02:45:16 by don              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define UHEX "0123456789ABCDEF"
# define LHEX "0123456789abcdef"

int	ft_printf(const char *format, ...);
int	ft_putchar_pf(char c);
int	ft_putstr_pf(char *str);
int	ft_putaddr_pf(unsigned long long addr);
int	ft_putdecimal_pf(int n);
int	ft_putint_pf(int n);
int	ft_putuint_pf(unsigned int n);
int	ft_putlhex_pf(unsigned int n);
int	ft_putuhex_pf(unsigned int n);

#endif
