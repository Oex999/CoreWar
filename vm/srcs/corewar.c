#include <vm.h>

int				main(int argc, char **argv)
{
	t_state		state;

	if (argc > 1)
	{
		state.champ_count = 2; // DEBUG
		init_state(&state);
		create_process(&state, 1);
		create_process(&state, 2);
		printf("\nProcess 1 at %p\n", state.champions[0]);
		printf("Process 1 Registries at %p\n", state.champions[0]->registries);
		printf("Process 2 at %p\n", state.champions[1]);
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
