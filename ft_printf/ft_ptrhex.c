/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrhex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:05:43 by michen            #+#    #+#             */
/*   Updated: 2024/01/04 21:10:28 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_ul(unsigned long n)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (n < 16)
		i += write(1, &hex[n], 1);
	else if (n >= 16)
	{
		i += ft_hex_ul(n / 16);
		i += ft_hex_ul(n % 16);
	}
	return (i);
}

int	ft_ptrhex(unsigned long deci_nbr)
{
	int	i;

	if (deci_nbr == 0)
		return (ft_putstr_fd("(nil)", 1));
	i = ft_putstr_fd("0x", 1);
	i += ft_hex_ul(deci_nbr);
	return (i);
}
