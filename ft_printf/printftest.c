/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printftest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:47:52 by michen            #+#    #+#             */
/*   Updated: 2024/01/06 21:07:00 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		function_chars;
	va_list	arg;

	va_start(arg, str);
	function_chars = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
			function_chars += ft_id(str[++i], arg);
		else
		{
			ft_putchar_fd(str[i], 1);
			function_chars++;
		}
		i++;
	}
	va_end(arg);
	return (function_chars);
}

// int	main(void)
//{
//	int	b;
//	int	c;

//	// void	*t;
//	c = 123;
//	// t = 122;
//	/* TESTS DES % */
//	c = ft_printf("U:%u\n", -100);
//	b = printf("U:%u\n", -100);
//	// printf("LU:%lu\n", &c);
//	// b = printf("true:%p\n", &c);
//	// c = ft_printf("mine:%p\n", &c);
//	// c = ft_printf("Ul:%u\n", 100);
//	/* AFFICHAGE DES RETURN DU PRINTF */
//	printf("true:%d\n", b);
//	printf("mine:%d\n", c);
//}
