#include <vm.h>

void			init_state(t_state *state)
{
    state->cycles_to_die = 0;
	state->champ_count = 0;
	state->dump = 0;
	state->live_champs = malloc(sizeof(char) * 5);
	ft_strcpy(state->live_champs, "0000");
	state->prev_lc = malloc(sizeof(char) * 5);
	ft_strcpy(state->prev_lc, "0000");
	printf("live_champs = %s\n", state->live_champs);
	state->begin = malloc(sizeof(t_address));
	init_mem(state, state->begin, MEM_SIZE);
	state->champ = malloc(sizeof(t_process *) * 4);
}

void			init_mem(t_state *state, t_address *current, int mem)
{
	current->operation = 0;
	current->acb = 0;
	current->arg1 = 0;
	current->arg2 = 0;
	current->arg3 = 0;
//	current->address = malloc(sizeof(char) * 255);
//	current->address = ft_itoabase(((mem - MEM_SIZE - 1) * -1), 16);
//	ft_strcpy(current->address, ft_itoabase(((mem - MEM_SIZE - 1) * -1), 16));
	current->address = ((mem - MEM_SIZE * 5) * -1);
	if (mem == 1)
		current->next = state->begin;
	else
	{
		current->next = malloc(sizeof(t_address));
		init_mem(state, current->next, mem - 6);
	}
}

void			create_process(t_state *state, int champ_no)
{
	t_process	*pointer;

	printf("\n\nstate->champs[%i] = %p\n", champ_no - 1, state->champ[champ_no - 1]);
	if (state->champ[champ_no - 1] != NULL)
	{
		printf("Creating Successive Process For Champion %i\n", champ_no);
		pointer = state->champ[champ_no - 1];
		while (pointer->next != NULL)
			pointer = pointer->next;
		pointer->next = malloc(sizeof(t_process));
		//pointer->next->registries = malloc(sizeof(long int *) * REG_NUMBER);
		init_process(pointer->next, champ_no);
	}
	else
	{
		printf("Creating First Process For Champion %i\n", champ_no);
		state->champ[champ_no - 1] = malloc(sizeof(t_process));
		printf("New Process at %p\n", state->champ[champ_no - 1]);
		init_process(state->champ[champ_no - 1], champ_no);
	}
}

void			init_process(t_process *process, int champ_no)
{
	//printf("init_process for champion %i\n", champion_no);
	//printf("t_process %p \n", process);
	process->champ_name = malloc(sizeof(char) * PROG_NAME_LENGTH + 2);
	process->champ_name[PROG_NAME_LENGTH + 1] = '\0';
	process->champ_comment = malloc(sizeof(char) * COMMENT_LENGTH + 2);
	process->champ_comment[COMMENT_LENGTH + 1] = '\0';
	process->alive = 0;
	process->carry = 0;
	process->pc = NULL;
	process->current_op.operation = 0;
	process->cycles_to_execute = 0;
	process->ops_executed = 0;
	process->next = NULL;
	process->champ_no = champ_no;
	process->registries = malloc(sizeof(int *) * REG_NUMBER);
	//printf("Champion number = %i\n", process->champion_no);
	//printf("Registries Malloced at %p\n", process->registries);
	init_reg(process);	
	//printf("Registries Initialized at %p\n", process->registries);
}

void			init_reg(t_process *process)
{
	int			index;

	//printf("Initializing Registries for Process at %p\n", process);
	index = -1;
	while(++index != 16)
	{
		if (index == 0)
			process->registries[index] = process->champ_no;
		else
			process->registries[index] = 0;
		//printf("Registry index %i initialized to %i\n",
		//		index, process->registries[index]);
	}
}

