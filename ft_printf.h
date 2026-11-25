/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idea <idea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:50:07 by mbodin            #+#    #+#             */
/*   Updated: 2026/11/25 12:16:12 by idea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

int			ft_printf(const char *format, ...);
int			ft_putstr(char *str);
int			ft_putchar(char c);
int			ft_putnbr(int nb);
int			ft_hex(unsigned int nb, char format);
static int	ft_put_ptr_hex(unsigned long nb);

#endif