/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodin <mbodin@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:50:07 by mbodin            #+#    #+#             */
/*   Updated: 2026/11/26 16:04:20 by mbodin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

int			ft_printf(const char *format, ...);
int			ft_dispatch(va_list args, char c);
int			ft_putstr(char *str);
int			ft_putchar(char c);
int			ft_putnbr(int nb);
int			ft_hex(unsigned int nb, char format);
int			ft_print_ptr(void *ptr);
int			ft_unsigned_putnbr(unsigned int nb);

#endif