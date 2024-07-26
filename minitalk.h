/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:06:59 by michen            #+#    #+#             */
/*   Updated: 2024/07/26 22:14:02 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <unistd.h>

void	ft_putstr(char *s);
long	ft_atol(const char *nptr);
void	sig_handler(int signal);

#endif