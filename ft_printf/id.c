/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:02:01 by michen            #+#    #+#             */
/*   Updated: 2024/01/04 21:13:51 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			i += ft_putstr_fd("-2147483648", 1);
			return (i);
		}
		i += ft_putchar_fd('-', 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	else if (nb >= 0 && nb <= 9)
		i += ft_putchar_fd(nb + '0', 1);
	return (i);
}

static unsigned int	ft_putnbr_unsigned(unsigned int nb)
{
	unsigned int	i;

	i = 0;
	if (nb >= 10)
	{
		i += ft_putnbr_unsigned(nb / 10);
		i += ft_putnbr_unsigned(nb % 10);
	}
	else if (nb >= 0 && nb <= 9)
		i += ft_putchar_fd(nb + '0', 1);
	return (i);
}

static int	ft_idbis(char c, va_list arg)
{
	int	i;

	i = 0;
	if (c == 'd' || c == 'i')
		i = ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		i = ft_putnbr_unsigned(va_arg(arg, unsigned int));
	else if (c == 'x')
		i = ft_lohex(va_arg(arg, unsigned int));
	else if (c == 'X')
		i = ft_uphex(va_arg(arg, unsigned int));
	return (i);
}

int	ft_id(char c, va_list arg)
{
	char	car;
	int		i;

	if (c == 'c')
	{
		car = va_arg(arg, int);
		i = ft_putchar_fd(car, 1);
	}
	else if (c == 's')
		i = ft_putstr_fd(va_arg(arg, char *), 1);
	else if (c == 'p')
	{
		i = ft_ptrhex(va_arg(arg, unsigned long));
	}
	else if (c == '%')
		i = write(1, &c, 1);
	else
		i = ft_idbis(c, arg);
	return (i);
}
