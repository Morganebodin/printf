/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodin <mbodin@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:01:21 by mbodin            #+#    #+#             */
/*   Updated: 2026/11/24 16:27:11 by mbodin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dispatch(va_list args, char c)
{
	int	sum;

	sum = 0;
	if (c == 'c')
		sum = ft_putchar(va_arg(args, int));
	else if (c == 's')
		sum = ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		sum = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		sum = ft_putnbr((int)va_arg(args, unsigned int));
	else if (c == 'x')
		sum = ;
	else if (c == 'X')
		sum = ;
	else if (c == 'p')
		sum = ;
	else
		sum = ft_putchar('%');
	return (sum);
}