#include <vm.h>

int				main(int argc, char **argv)
{
	t_state		state;
    int         i;

	if (argc > 1)
	{
        i = argc - 1;
		init_state(&state);
        parse_user_input(&state, argv, i);
		play_game(&state);
	}
	else
    {
		ft_putstr("No Input Given. Usage - ./corewar [-dump nbr_cycles] ");
		ft_putendl("[[-n number] champion1.cor] ...");
	}
	return (0);
}
