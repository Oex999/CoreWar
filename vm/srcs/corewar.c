#include <vm.h>

int				main(int argc, char **argv)
{
	t_state		state;

	if (argc > 1)
	{
		init_state(&state);
	
		//read and validate champions here
		//init_process;
		
		(void)argc; //Just so we can compile to test. Remove
		(void)argv;
		free_state(&state);
	}
	else
	{
		ft_putstr("No Input Given. Usage - ./corewar [-dump nbr_cycles] ");
		ft_putendl("[[-n number] champion1.cor] ...");
	}
	return (0);
}
