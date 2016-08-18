#include <vm.h>

int				main(int argc, char **argv)
{
	t_state		state;
    int         i;

	if (argc > 1)
	{
        i = argc - 1;
        printf("Initial state.cycles_to_die set to %i\n", state.cycles_to_die);//debuggery
        parse_cycles_to_die(&state, argv, i);
        printf("After parse_cycles_to_die call, cycles_to_die value = %i\n", state.cycles_to_die);//debuggery
        write(1, "\n", 1);//debug
        write(1, "\n", 1);//debug
        printf("Initial state.champ_count set to %i\n", state.champ_count);//debuggery
        parse_champ_count(&state, argv, i);
        printf("After parse_champ_count call, champ_count = %i\n", state.champ_count);//debuggery
        //parse_champ_number(&state, argv, i);
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
