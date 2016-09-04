#include <vm.h>

void			free_state(t_state *state)
{
	int			k;
	
	printf("\n\t\t\x1b[36mFreeing State\x1b[0m\n\n");
	free_mem(state->begin, MEM_SIZE);
	k = state->champ_count;
	while (k > 0)
	{
		if (state->champ[k - 1])
			free_champ(state->champ[k - 1]);
		k--;
	}
	free(state->champ);
	free(state->live_champs);
	free(state->prev_lc);
}

void			free_mem(t_address *current, int mem)
{
	t_address	*temp;

	if (mem != 0)
		temp = current->next;
	free(current);
	if (mem != 1)
		free_mem(temp, mem - 1);
}

void			free_reg(t_process *process)
{
	int			index;

	index = -1;
	while (++index != 16)
	{
		//free(process->registries[index]);
	}
	free(process->registries);
}

void			free_process(t_process *process)
{
	free(process->champ_name);
	free(process->champ_comment);
	free_reg(process);
	free(process);
}

void			free_champ(t_process *champ)
{
	t_process *temp;

	temp = champ->next;
	if (temp)
		free_champ(temp);
	free_process(champ);
}
