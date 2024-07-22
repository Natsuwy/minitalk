/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:05:37 by michen            #+#    #+#             */
/*   Updated: 2024/01/04 20:54:16 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lohex(unsigned int n)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (n < 16)
		i += write(1, &hex[n], 1);
	else if (n >= 16)
	{
		i += ft_lohex(n / 16);
		i += ft_lohex(n % 16);
	}
	return (i);
}

int	ft_uphex(unsigned int n)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789ABCDEF";
	if (n < 16)
		i += write(1, hex + n, 1);
	else if (n >= 16)
	{
		i += ft_uphex(n / 16);
		i += ft_uphex(n % 16);
	}
	return (i);
}
