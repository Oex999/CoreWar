#include <vm.h>

void			init_state(t_state *state)
{
	//int			i;
	
	state->cycles_to_die = CYCLE_TO_DIE;
	state->checks_done = 0;
	state->dump = 0;
	state->begin = malloc(sizeof(t_address));
	init_mem(state, state->begin, MEM_SIZE);
	state->champions = ft_memalloc(state->champ_count);
	//i = -1;
	//while (++i < state->champ_count)
	//{
	//	state->champions[i] = malloc(sizeof(t_process));
	//	printf("t_process %p \n", state->champions[i]);
	//}
	/*printf("State Initialized\n");
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
	process->registries = (int *)malloc(sizeof(int *) * REG_NUMBER);
	//while(++index != 16)
	//	process->registries[index] = ft_memalloc(REG_SIZE);
	process->registries[index] = 0;
	process->registries[0] = process->champion_no;
}

void			init_process(t_state *state, int champion_no)
{
	t_process	*process;

	printf("init_process\n");
	process = state->champions[champion_no - 1];
	printf("t_process %p \n", process);
	//printf("Seeking New Process Pointer\n");
	//if (process = NULL
	//while (process->next != NULL)
	//{
	//	process = process->next;
	//	printf("t_process %p \n", process);
	//}
	//printf("New Process Pointer Found\n");
	//process->next = malloc(sizeof(t_process));
	//process = process->next;
	printf("Process Malloced\n");
	process->champion_name = malloc(sizeof(char) * PROG_NAME_LENGTH + 1);
	process->champion_name[PROG_NAME_LENGTH + 1] = '\0';
	process->champion_comment = malloc(sizeof(char) * COMMENT_LENGTH + 1);
	process->champion_comment[COMMENT_LENGTH + 1] = '\0';
	process->champion_no = champion_no;
	printf("Process Malloced\n");
	process->alive = 0;
	process->carry = 0;
	process->pc = NULL;
	process->next = NULL;
	process->has_next = 0;
	init_reg(process);	
}
