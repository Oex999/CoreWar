#include <vm.h>

void			free_state(t_state *state)
{
	int			k;
	
	printf("\n\t\t\x1b[36mFreeing State\x1b[0m\n\n");
	free_mem(state->begin, MEM_SIZE);
	printf("Memory succesfully freed\n\n");
	//printf("State->ChampCount = %i\n", state->champ_count);
	k = state->champ_count;
	while (k > 0)
	{
		//printf("Freeing champion[%i]\n", k - 1);
		//printf("Registries at %p\n", state->champ[k - 1]->registries);
		if (state->champ[k - 1])
			free_champ(state->champ[k - 1]);
		//printf("champ[%i] succesfully freed\n\n", k - 1);
		k--;
	}
	free(state->champ);
	printf("champ succesfully freed\n");
	free(state->live_champs);
	printf("Live_Champs List succesfully freed\n");
	free(state->prev_lc);
	printf("Previous Live Champs List succesfully freed\n");
}

void			free_mem(t_address *current, int mem)
{
	t_address	*temp;
//	char		*str;

//	str = ft_itoabase(current->address, 16);
//	printf("Freeing Address %s\n", str);
//	free(str);
	if (mem != 0)
		temp = current->next;
//	free(current->address);
	free(current);
	if (mem != 1)
		free_mem(temp, mem - 1);
}

void			free_reg(t_process *process)
{
	int			index;

	//printf("Freeing registries at %p\n", process->registries);
	index = -1;
	while (++index != 16)
	{
		//printf("Freeing registry[%i] = %i\n", index, process->registries[index]);
		//free(process->registries[index]);
	}
	free(process->registries);
}

void			free_process(t_process *process)
{
	free(process->champ_name);
	free(process->champ_comment);
	//printf("Name & Champion succesfully freed\n");
	//printf("free_process at %p\n", process);
	//printf("free_process Registries at %p\n", process->registries);
	free_reg(process);
	//printf("Registries succesfully freed\n");
	free(process);
}

void			free_champ(t_process *champ)
{
	t_process *temp;

	//printf("Champion Process %p\n", champion);
	//printf("Champion->next Process %p\n", champion->next);
	temp = champ->next;
	if (temp)
	{
		//printf("Freeing Successive Champion Process\n\n");
		free_champ(temp);
	}
	//printf("Freeing Champion Process at %p\n", champion);
	//printf("free_champion Registries at %p\n", champion->registries);
	free_process(champ);
	//printf("Process succesfully freed\n");
}
