/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamecycles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaunder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 13:58:40 by bsaunder          #+#    #+#             */
/*   Updated: 2016/09/06 14:02:26 by bsaunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void				play_game(t_state *state)
{
	unsigned int	cycle;
	unsigned int	cycles_left;
	int				checks_done;
	int				modified_ctd;

	modified_ctd = 1;
	cycle = 0;
	cycles_left = state->dump - 1;
	checks_done = 0;
	printf("\n\t\t\x1b[35mStarting game\x1b[0m\n\n");
	declare_champs(state);
	while (state->cycles_to_die <= CYCLE_TO_DIE)
	{
		cycle++;
		if (state->dump != 0)
		{
			if (cycles_left-- == 0)
				dump_memory(state);
		}
		run_champs(state);
		if (cycle % state->cycles_to_die == 0 && cycle != 0)
		{
			prune_champs(state);
			check_nbr_live(state);
			checks_done++;
			modified_ctd = 0;
		}
		if (checks_done % MAX_CHECKS == 0 && modified_ctd == 0)
		{
			state->cycles_to_die -= CYCLE_DELTA;
			modified_ctd = 1;
		}
		if (ft_strcmp(state->live_champs, "0000") != 0)
			ft_strcpy(state->prev_lc, state->live_champs);
	}
	check_for_winner(state);
}

void				declare_champs(t_state *state)
{
	int				i;

	ft_putstr("Declaring Champions!\n\n");
	i = 0;
	while (i < state->champ_count)
	{
		ft_putstr("Player ");
		ft_putstr(ft_itoabase((i + 1), 10));
		ft_putstr("\t");
		ft_putstr(state->champ[i]->champ_name);
		ft_putstr(",\nComment: ");
		ft_putstr(state->champ[i]->champ_comment);
		ft_putstr("\n\n");
		i++;
	}
	ft_putstr("\n");
}

void				prune_champs(t_state *state)
{
	t_process		*temp;
	t_process		*iter;
	int				i;

	i = -1;
	while (++i < 4)
		if (state->champ[i] != NULL)
		{
			temp = state->champ[i];
			while (temp->next)
			{
				if (temp->next->alive < 1)
				{
					iter = temp->next;
					temp->next = temp->next->next;
					free_process(iter);
				}
				temp->alive = 0;
				temp = temp->next;
			}
			if (temp == state->champ[i] && temp->alive < 1)
			{
				printf("Champions First Process Did Not Report Live\n");
				state->champ[i] = state->champ[i]->next;
				free_process(temp);
			}
		}
}

void				dump_memory(t_state *state)
{
	t_address		*mem;
	int				done;

	mem = state->begin;
	done = 0;
	while (done != 2)
	{
		if (mem->address == MEM_SIZE || mem->address == 1)
			done++;
	}
	error_exit(state, "Memory Dumped As Per -dump Flag\n");
}
