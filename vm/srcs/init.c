#include <vm.h>

void	init_state(t_state *state)
{
	state->cycles_to_die = CYCLES_TO_DIE;
	state->checks_done = 0;
	init_mem(state, state->*begin, MEM_SIZE);
	state->champions = ft_memalloc(4);
}

void	init_mem(t_state *state, t_address *current, int mem)
{
	current = malloc(sizeof(t_address) * 1);
	instruction = (char)malloc(sizeof(char) * 8); //CHECK Instruction Sizes
	address = (char)malloc(sizeof(char) * 255);
	address = ft_itoabase(mem, 16);
	// create way to find previous address to create previous link
	// pass next to init mem with decremented mem
	// if mem = 1, next = state->begin
}

void	init_reg(t_process *process)
{
	size_t	index;

	index = -1;
	registries = (void**)malloc(sizeof(void*) * REG_NUMBER);
	while(++index != 16)
		registries[index] = ft_memalloc(REG_SIZE);
	registries[index] = NULL;
}

