/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:32:28 by michen            #+#    #+#             */
/*   Updated: 2024/01/04 20:30:45 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_id(char c, va_list arg);
int	ft_lohex(unsigned int n);
int	ft_uphex(unsigned int n);
int	ft_ptrhex(unsigned long decinbr);
int	ft_printf(const char *str, ...);

#endif