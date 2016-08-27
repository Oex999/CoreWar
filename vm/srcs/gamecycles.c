#include <vm.h>

void				play_game(t_state *state)
{
	unsigned int	cycle;
	unsigned int	cycles_left;
	int				checks_done;
	//int				cycle_deltas;
	int				modified_ctd;

	modified_ctd = 1;
	ft_strcpy(state->champions[0]->champion_name, "test");
	cycle = 0;
	cycles_left = state->dump -	1;
	checks_done = 0;
	//cycle_deltas = 0;
	printf("\n\t\t\x1b[35mStarting game\x1b[0m\n\n");
	declare_champs(state);
	while (state->cycles_to_die <= CYCLE_TO_DIE)
	{
		cycle++;
		//state->cycles_to_die--;
		printf("Current Cycle = %i\tCycles_To_Die = %i\tChecks_Done = %i\n", cycle, state->cycles_to_die, checks_done);
		if (state->dump != 0)
		{
			printf("cycles left until dump = %i\n", cycles_left);
			if (cycles_left-- == 0)
				dump_memory(state);
		}
		run_champs(state);
		if (cycle % state->cycles_to_die == 0 && cycle != 0)
		{
			prune_champs(state);
			check_nbr_live(state);
			checks_done++;
			modified_ctd = 0;
			//state->cycles_to_die = CYCLE_TO_DIE - (CYCLE_DELTA * cycle_deltas);
		}
		if (checks_done % MAX_CHECKS == 0 && modified_ctd == 0)
		{
			//cycle_deltas++;
			//checks_done = 0;
			state->cycles_to_die -= CYCLE_DELTA;
			modified_ctd = 1;
		}
		if (ft_strcmp(state->live_champs, "0000") != 0)
			ft_strcpy(state->prev_lc, state->live_champs);
		printf("plc = %s \t lc = %s\n", state->prev_lc, state->live_champs);
	}
	check_for_winner(state);
}

void			declare_champs(t_state *state)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		if (state->champions[i])
		{
			ft_putstr("Player ");
			ft_putstr(ft_itoabase((i + 1), 10));
			ft_putstr("\t");
			ft_putstr(state->champions[i]->champion_name);
			ft_putchar(' ');
			ft_putstr(state->champions[i]->champion_comment);
			ft_putstr("\n");
		}
		i++;
	}
	ft_putstr("\n");
}

void			prune_champs(t_state *state)
{
	t_process	*temp;
	t_process	*iter;
	int			i;

	printf("Pruning Champs\n");
	i = -1;
	while (++i < 4)
		if (state->champions[i] != NULL)
		{
			printf("First Process for champ %i exists\n", i);
			temp = state->champions[i];
			while (temp->next)
			{
				printf("First Process has successive process\n");
				if (temp->next->alive < 1)
				{
					printf("Successive Process Did Not Report Live\n");
					iter = temp->next;
					temp->next = temp->next->next;
					free_process(iter);
				}
				temp->alive = 0;
				temp = temp->next;
			}
			if (temp == state->champions[i] && temp->alive < 1)
			{
				printf("Champions First Process Did Not Report Live\n");
				state->champions[i] = state->champions[i]->next;
				free_process(temp);
			}
		}
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
		/*
		   ft_puthex(mem->address);
		   ft_putstr("\t->\t");
		   ft_puthex(mem->operation);
		   ft_putchar(' ');
		   ft_puthex(mem->acb);
		   ft_putchar(' ');
		   ft_puthex(mem->arg1);
		   ft_putchar(' ');
		   ft_puthex(mem->arg2);
		   ft_putchar(' ');
		   ft_puthex(mem->arg3);
		   ft_putchar(' ');
		   ft_puthex((mem->arg4);
		   ft_putchar('\n');
		   mem = mem->next;
		   */

//		if (ft_strcmp(mem->address, "1000") == 0 
//				|| ft_strcmp(mem->address, "1") == 0)
		if (mem->address == MEM_SIZE || mem->address == 1)
			done++;
	}
	error_exit(state, "Memory Dumped As Per -dump Flag\n");
}
