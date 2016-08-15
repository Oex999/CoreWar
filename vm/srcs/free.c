#include <vm.h>

void			free_state(t_state *state)
{
	free_mem(state->begin, MEM_SIZE);
}

void			free_reg(t_process *process)
{

}

void			free_mem(t_address *current, int mem)
{
	t_address	*temp;

	if (mem != 0)
		temp = current->next;
	free(current->address);
	free(current);
	if (mem != 0)
		free_mem(temp, mem - 1);
}

void			free_process(t_process *process)
{
	
}
