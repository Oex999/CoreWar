#include <vm.h>

void				play_game(t_state *state)
{
	unsigned int	cycles_run;
	unsigned int	cycles_left;
	int				check_done;

	cycles_run = 0;
	cycles_left = state->dump;
	printf("\n\t\t\x1b[35mStarting game\x1b[0m\n\n");
	declare_champs(state);
	while (cycles_run <= state->cycles_to_die)
	{
		printf("cycles left until dump = %i\n", cycles_left);
		if (cycles_left == 0)
			dump_memory(state);
		//check champion->process for a current operation 
		//		else, run champion->process[next]
		//		process command at process->pc, update current operation
		//check next champion
		//check number of cycles
		//if cycles reaches 0, check live status
		//	kill non living processes
		//check if still more than one champion with living processes
		//reset cycles to die.
		//if cycles to die reset MAX_CHECKS times
		//	reduce cycles to die max by cycles delta
		cycles_run++;
	}
}

void			declare_champs(t_state *state)
{
	(void)state;
}

void			execute_cmd(t_process *process)
{
	(void)process;
}

void			kill_process(t_state *state, t_process *process)
{
	(void)state;
	(void)process;
}

void			dump_memory(t_state *state)
{	
	t_address	*mem;
	
	printf("Dumping Memory\n");
	mem = state->begin;
	while (ft_strcmp(mem->address, "1000") == 0)
	{
		
	}
	//print memory to stdi
	error_exit(state, "Memory dumped according to -dump flag\n");
}
