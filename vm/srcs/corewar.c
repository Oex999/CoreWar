#include <vm.h>

int				main(int argc, char **argv)
{
	t_state		state;
    int         i;

	if (argc > 1)
	{
        i = argc - 1;
		init_state(&state);
        printf("Initial state.cycles_to_die set to %i\n\n", state.cycles_to_die);//debuggery
        parse_user_input(&state, argv, i);
		printf("\n\t\tFreeing State\n\n");//debuggery
		free_state(&state);
	}
	else
	{
		ft_putstr("No Input Given. Usage - ./corewar [-dump nbr_cycles] ");
		ft_putendl("[[-n number] champion1.cor] ...");
	}
	return (0);
}
