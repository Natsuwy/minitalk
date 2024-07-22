#include "minitalk.h"

int	main(int ac, char **av)
{
	int pid;
	char *str;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid == -1)
			return (0);
		str = av[2];
		if (pid != -1)
			printf("OK\n");
	}
}