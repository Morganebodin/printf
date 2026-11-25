/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idea <idea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:51:27 by mbodin            #+#    #+#             */
/*   Updated: 2026/11/25 12:20:33 by idea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	int	sum;

	sum = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		sum = sum + ft_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	sum = sum + ft_putchar(nb % 10 + '0');
	return (sum);
}

int	ft_hex(unsigned int nb, char format)
{
	int	sum;
	int	mod;

	sum = 0;
	if (nb >= 16)
		sum = sum + ft_hex(nb / 16, format);
	mod = nb % 16;
	if (mod >= 10)
	{
		if (format == 'x')
			ft_putchar(mod - 10 + 'a');
		else
			ft_putchar(mod - 10 + 'A');
	}
	else
		ft_putchar(mod + '0');
	sum++;
	return (sum);
}

static int	ft_put_ptr_hex(void *ptr)
{
	uintptr_t	nb;

	nb = (uintptr_t)ptr;

}