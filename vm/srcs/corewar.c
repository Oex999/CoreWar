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
