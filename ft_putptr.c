/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodin <mbodin@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 15:28:38 by mbodin            #+#    #+#             */
/*   Updated: 2026/11/26 15:53:09 by mbodin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_ptr_hex(void *ptr)
{
	uintptr_t	nb;
	int			sum;
	int			mod;

	nb = (uintptr_t)ptr;
	mod = nb % 16;
	sum = 0;
	if (nb >= 16)
		sum = sum + ft_put_ptr_hex((void *)(nb/16));
	if (mod >= 10)
		ft_putchar(mod - 10 + 'a');
	else
		ft_putchar(mod + '0');
	sum++;
	return (sum);
}

int	ft_print_ptr(void *ptr)
{
	int	sum;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	sum = 0;
	write(1, "0x", 2);
	sum = sum + 2;
	sum = sum + ft_put_ptr_hex(ptr);
	return (sum);
}
