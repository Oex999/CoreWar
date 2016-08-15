#include <vm.h>

void			init_state(t_state *state)
{
	state->cycles_to_die = CYCLE_TO_DIE;
	state->checks_done = 0;
	state->dump = 0;
	state->begin = malloc(sizeof(t_address));
	init_mem(state, state->begin, MEM_SIZE);
	/*state->champions = ft_memalloc(4);
	printf("State Initialized\n");
	printf("state->cycles_to_die = %i\n", state->cycles_to_die);
	printf("state->checks_done = %i\n", state->checks_done);
	printf("state->dump = %i\n", state->dump);
	t_address *temp = state->begin->next;
	while (ft_strcmp(temp->address, state->begin->address) != 0)
	{
		printf("Address Pointer -\t%p\n", temp);
		printf("Address Designation -\t%s\n", temp->address);
		printf("Address Instruction -\t%i\n", temp->instruction);
		temp = temp->next;
	}*/
}

void			init_mem(t_state *state, t_address *current, int mem)
{
	//printf("State->begin Memory Element -\t%p\n", state->begin);
	current->instruction = 0xff;
	current->address = (char *)malloc(sizeof(char) * 255);
	current->address = ft_itoabase(((mem - MEM_SIZE - 1) * -1), 16);
	//printf("Memory Element Initialized -\t%s\n", current->address);
	//if (mem < MEM_SIZE)
	//	printf("Next Memory Element -\t%p\n", current->next);
	if (mem == 1)
		current->next = state->begin;
	else
	{
		current->next = ft_memalloc(sizeof(t_address));
		init_mem(state, current->next, mem - 1);
	}
}

void			init_reg(t_process *process)
{
	size_t		index;

	index = -1;
	process->registries = (void**)malloc(sizeof(void*) * REG_NUMBER);
	while(++index != 16)
		process->registries[index] = ft_memalloc(REG_SIZE);
	process->registries[index] = NULL;
}

