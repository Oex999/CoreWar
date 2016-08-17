#include <vm.h>

int				main(int argc, char **argv)
{
	t_state		state;

	if (argc > 1)
	{
		state.champ_count = 2; // DEBUG
		init_state(&state);
		//while (process && process->next != NULL)
		//	process = process->next;
		state.champions[0] = malloc(sizeof(t_address));
		state.champions[0]->has_next = 1;
		state.champions[1] = malloc(sizeof(t_address));
		state.champions[1]->has_next = 1;
		init_process(&state, 1);
		init_process(&state, 2);

		printf("Process 1 Registries at %p\n", state.champions[0]->registries);
		printf("Process 2 Registries at %p\n", state.champions[1]->registries);
	
		//read and validate champions here
		//init_process;
		
		(void)argc; //Just so we can compile to test. Remove
		(void)argv;
		printf("\n\t\tFreeing State\n\n");
		free_state(&state);
	}
	else
	{
		ft_putstr("No Input Given. Usage - ./corewar [-dump nbr_cycles] ");
		ft_putendl("[[-n number] champion1.cor] ...");
	}
	return (0);
}
