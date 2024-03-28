/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:40:45 by dohyuki2          #+#    #+#             */
/*   Updated: 2024/03/28 16:13:00 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define UHEX "0123456789ABCDEF"
# define LHEX "0123456789abcdef"

int ft_printf(const char *format, ...);
int ft_putchar_pf(char c);
int ft_putstr_pf(char *str);
int ft_putaddr_pf();
int ft_putdecimal_pf();
int ft_putint_pf();
int ft_putuint_pf();
int ft_putlhex_pf();
int ft_putuhex_pf();
int ft_putchar_pf();

#endif
