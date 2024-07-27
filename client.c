/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:58:30 by michen            #+#    #+#             */
/*   Updated: 2024/07/27 18:55:41 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_status;

void	sig_status(int signal)
{
	if (signal == SIGUSR1)
		g_status = 1;
	else if (signal == SIGUSR2)
		printf("Sent\n");
}

void	char_bin(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		while (!g_status)
			usleep(100);
		g_status = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	index;

	index = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		signal(SIGUSR1, &sig_status);
		signal(SIGUSR2, &sig_status);
		if (pid <= 0 || pid >= 4194305 || kill(pid, 0) == -1)
			return (write(2, "PID: Error wrong PID\n", 22), 1);
		while (av[2][index] != 0)
		{
			char_bin(pid, av[2][index]);
			index++;
		}
		if (index > 0 && !av[2][index])
			char_bin(pid, '\0');
	}
	return (0);
}
