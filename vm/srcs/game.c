#include <vm.h>

void				play_game(t_state *state)
{
	unsigned int	cycle;
	unsigned int	cycles_left;
	int				check_done;

	cycle = 0;
	cycles_left = state->dump;
	checks_done = 0;
	printf("\n\t\t\x1b[35mStarting game\x1b[0m\n\n");
	declare_champs(state);
	while (state->cycles_to_die <= CYCLE_TO_DIE)
	{
		printf("Current Cycle = %i\n", cycle);
		if (state->dump != 0)
		{
			printf("cycles left until dump = %i\n", cycles_left);
			if (cycles_left == 0)
				dump_memory(state);
			cycles_left--;
		}
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
		if (checks_done % MAX_CHECKS == 0)
		{
			state->cycles_to_die -= CYCLE_DELTA;
		}
		cycle++;
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
	int			done;
	
	printf("Dumping Memory\n");
	mem = state->begin;
	done = 0;
	while (done != 2)
	{
		ft_putstr(mem->address);
		ft_putstr("\t->\t");
		ft_putstr(ft_itoabase(mem->operation, 16));
		ft_putchar(' ');
		ft_putstr(ft_itoabase(mem->acb, 16));
		ft_putchar(' ');
		ft_putstr(ft_itoabase(mem->arg1, 16));
		ft_putchar(' ');
		ft_putstr(ft_itoabase(mem->arg2, 16));
		ft_putchar('\n');
		mem = mem->next;
		if (ft_strcmp(mem->address, "1000") == 0 
				|| ft_strcmp(mem->address, "1") == 0)
			done++;
	}
	error_exit(state, "Memory Dumped As Per -dump Flag\n");
}
