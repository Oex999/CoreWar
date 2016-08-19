#include <vm.h>

void			init_state(t_state *state)
{
    //int         i;
    
    state->cycles_to_die = 0;
	state->champ_count = 0;
	state->checks_done = 0;
	state->dump = 0;
	state->live_champs = malloc(sizeof(char) * 4);
	ft_strcpy(state->live_champs, "0000");
	printf("live_champs = %s\n", state->live_champs);
	state->begin = malloc(sizeof(t_address));
	init_mem(state, state->begin, MEM_SIZE);
	state->champions = malloc(sizeof(t_process *) * 4);
    //i = 0;
    //while (i++ < 4)
    //    state->champions[i] = NULL;
}

void			init_mem(t_state *state, t_address *current, int mem)
{
	current->instruction = 0;
	current->address = (char *)malloc(sizeof(char) * 255);
	current->address = ft_itoabase(((mem - MEM_SIZE - 1) * -1), 16);
	if (mem == 1)
		current->next = state->begin;
	else
	{
		current->next = malloc(sizeof(t_address));
		init_mem(state, current->next, mem - 1);
	}
}

void			create_process(t_state *state, int champion_no)
{
	t_process	*pointer;

	printf("\n\nstate->champions[%i] = %p\n", champion_no - 1, state->champions[champion_no - 1]);
	if (state->champions[champion_no - 1] != NULL)
	{
		printf("Creating Successive Process For Champion %i\n", champion_no);
		pointer = state->champions[champion_no - 1];
		while (pointer->next != NULL)
			pointer = pointer->next;
		pointer->next = malloc(sizeof(t_process));
		//pointer->next->registries = malloc(sizeof(long int *) * REG_NUMBER);
		init_process(pointer->next, champion_no);
	}
	else
	{
		printf("Creating First Process For Champion %i\n", champion_no);
		state->champions[champion_no - 1] = malloc(sizeof(t_process));
		printf("New Process at %p\n", state->champions[champion_no - 1]);
		init_process(state->champions[champion_no - 1], champion_no);
	}
}

void			init_process(t_process *process, int champion_no)
{
	printf("init_process for champion %i\n", champion_no);
	printf("t_process %p \n", process);
	process->champion_name = malloc(sizeof(char) * PROG_NAME_LENGTH + 1);
	process->champion_name[PROG_NAME_LENGTH + 1] = '\0';
	process->champion_comment = malloc(sizeof(char) * COMMENT_LENGTH + 1);
	process->champion_comment[COMMENT_LENGTH + 1] = '\0';
	process->alive = 0;
	process->carry = 0;
	process->pc = NULL;
	process->next = NULL;
	process->has_next = 0;
	process->champion_no = champion_no;
	process->registries = malloc(sizeof(int *) * REG_NUMBER);
	printf("Champion number = %i\n", process->champion_no);
	printf("Registries Malloced at %p\n", process->registries);
	init_reg(process);	
	printf("Registries Initialized at %p\n", process->registries);
}

void			init_reg(t_process *process)
{
	int			index;

	printf("Initializing Registries for Process at %p\n", process);
	index = -1;
	while(++index != 16)
	{
		if (index == 0)
			process->registries[index] = process->champion_no;
		else
			process->registries[index] = 0;
		printf("Registry index %i initialized to %i\n",
				index, process->registries[index]);
	}
}

