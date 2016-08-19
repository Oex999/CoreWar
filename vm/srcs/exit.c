#include <vm.h>

void		error_exit(t_state *state, char *message)
{
	ft_putstr(message);
	free_state(state);
	exit(-1);
}
