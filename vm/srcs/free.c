#include <vm.h>

void			free_state(t_state *state)
{
	int			k;
	
	free_mem(state->begin, MEM_SIZE);
	printf("Memory succesfully freed\n");
	k = state->champ_count;
	while (k > 0)
	{
		printf("freeing champion[%i]\n", k - 1);
		free_champion(state->champions[k - 1]);
		printf("champions[%i] succesfully freed\n", k - 1);
		k--;
	}
	free(state->champions);
	printf("Champions succesfully freed\n");
}

void			free_reg(t_process *process)
{
	size_t		index;

	index = -1;
	while (++index != 16)
	{
		printf("freeing registry[%zu] = %i\n", index, process->registries[index]);
		//free(process->registries[index]);
	}
	free(process->registries);
}

void			free_mem(t_address *current, int mem)
{
	t_address	*temp;

	//printf("Freeing Address %s\n", current->address);
	if (mem != 0)
		temp = current->next;
	free(current->address);
	free(current);
	if (mem != 1)
		free_mem(temp, mem - 1);
}

void			free_process(t_process *process)
{
	free(process->champion_name);
	free(process->champion_comment);
	printf("Name & Champion succesfully freed\n");
	free_reg(process);
	printf("Registries succesfully freed\n");
	free(process);
}

void			free_champion(t_process *champion)
{
	t_process	*temp;

	temp = champion;
	if (champion != NULL)
	{
		printf("Freeing Process %p\n", champion);
		//if (champion->next != NULL)
		if (champion->has_next == 1)
		{
			printf("Freeing next Process %p\n", champion->next);
			free_champion(champion->next);
		}
		printf("freeing\n");
		free_process(champion);
		printf("Process succesfully freed\n");
	}
}
