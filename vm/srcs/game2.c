#include <vm.h>

void			check_for_winner(t_state *state)
{
	int			i;
	int			living;
	t_process	winner;

	i = -1;
	living = 0;
	while (++i < 4)
	{
		if (state->champions[i] != NULL)
		{
			living++;
			winner = *state->champions[i];
		}
	}
	if (living == 0)
		error_exit(state, "\x1b[35mNo Winner, all Processes Dead\n\x1b[0m");
	if (living == 1)
	{
		ft_putstr(winner.champion_name);
		error_exit(state, "\x1b[35mWon!\n\x1b[0m");
	}
	if (living > 1)
		error_exit(state, 
				"\x1b[35mDraw - Multiple Champions Still ALive\n\x1b[0m");
}
