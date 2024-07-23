#include "minitalk.h"

void	signal_hahamdulila(int signal, siginfo_t siginfo, void *context)
{
	(void)context;
	if (siginfo.info == SIGUSR1)
		printf("siguser1\n");
	else if (siginfo.info == SIGUSR2)
		printf("siguser2\n");
}

int	main(void)
{
	struct sigaction sa;

	ft_printf("%d\n", getpid());

	sa.sa_handler = &signal_hahamdulila;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;

	if (sigaction(SIGUSR1, (const struct sigaction *)&signal_hahamdulila,
			NULL) == -1)
	{
		write(2, "SIGACTION ERROR\n", 17);
		return (1);
	}
	if (sigaction(SIGUSR2, (const struct sigaction *)&signal_hahamdulila,
			NULL) == -1)
	{
		write(2, "SIGACTION ERROR\n", 17);
		return (1);
	}
	while (1)
		pause();
	return (0);
}