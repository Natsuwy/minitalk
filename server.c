/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:58:09 by michen            #+#    #+#             */
/*   Updated: 2024/07/27 19:07:04 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_build_string(char c, siginfo_t *info)
{
	static char	*str = NULL;

	if (c == 0)
	{
		ft_putstr_fd(str, 1);
		ft_putstr_fd("\n", 1);
		kill(info->si_pid, SIGUSR2);
		free(str);
		str = NULL;
	}
	else
		str = ft_strjoin_bis(str, c);
}

void	bin_char(int signum, siginfo_t *info, void *context)
{
	static int	bit;
	static char	c;

	(void)context;
	if (signum == SIGUSR1)
		c = (c << 1) | 1;
	else if (signum == SIGUSR2)
		c <<= 1;
	if (bit < 7)
		bit++;
	else
	{
		ft_build_string(c, info);
		c = 0;
		bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &bin_char;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("%d\n", getpid());
	while (1)
		pause();
	write(1, "\n", 1);
	return (0);
}