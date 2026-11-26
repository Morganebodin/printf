/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodin <mbodin@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:41:13 by mbodin            #+#    #+#             */
/*   Updated: 2026/11/26 15:10:57 by mbodin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int				i;
	va_list			args;
	int				sum;

	sum = 0;
	i = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			sum = sum + ft_dispatch(args, format [i +1]);
			i++;
		}
		else
			sum = sum + ft_putchar(format [i]);
		i++;
	}
	va_end(args);
	return (sum);
}
