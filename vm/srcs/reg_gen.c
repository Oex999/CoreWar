#include "../includes/vm.h"
#include "../includes/op.h"
#include "../includes/libft.h"

void	**registries()
{
	t_process	process;
	void	**registries;
	size_t	elements;
	size_t	index;
	elements = 17;
	index = -1;
	registries = (void**)malloc(sizeof(void*) * elements);
	while(index != endex)
	{
		registries[++index] = (*(process->data) = memalloc(REG_SIZE));
		process = process->next;
	}
	return ap;
}

