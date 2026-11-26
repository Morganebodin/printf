/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodin <mbodin@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:01:21 by mbodin            #+#    #+#             */
/*   Updated: 2026/11/26 16:04:43 by mbodin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dispatch(va_list args, char c)
{
	int		sum;

	sum = 0;
	if (c == 'c')
		sum = ft_putchar(va_arg(args, int));
	else if (c == 's')
		sum = ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		sum = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		sum = ft_unsigned_putnbr(va_arg(args, unsigned int));
	else if (c == 'x')
		sum = ft_hex(va_arg(args, unsigned int), c);
	else if (c == 'X')
		sum = ft_hex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		sum = ft_print_ptr(va_arg(args, void *));
	else
		sum = ft_putchar('%');
	return (sum);
}
