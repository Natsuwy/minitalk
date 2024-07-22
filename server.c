#include "minitalk.h"

int	main(void)
{
	struct sigaction sa;

	ft_printf("%d\n", getpid());
	while (1)
		pause();
}