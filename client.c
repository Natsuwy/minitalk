#include "minitalk.h"

int	main(int ac, char **av)
{
	long	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid >= 4194305 || pid <= 0 || kill(pid, 0) == -1)
			return (write(2, "Error\n", 6), 1);
		kill(pid, SIGUSR1);
	}
	return (0);
}
