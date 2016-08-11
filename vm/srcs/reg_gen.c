#include <vm.h>

void	**init_reg(t_process *process)
{
	size_t	index;

	index = -1;
	registries = (void**)malloc(sizeof(void*) * REG_NUMBER);
	while(++index != 16)
		registries[index] = (*(process->data) = memalloc(REG_SIZE));
	registries[index] = NULL;
}

