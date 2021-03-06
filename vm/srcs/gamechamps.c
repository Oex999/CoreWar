/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamechamps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaunder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 13:43:58 by bsaunder          #+#    #+#             */
/*   Updated: 2016/09/06 14:03:56 by bsaunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (state->champ[i] != NULL)
		{
			living++;
			winner = *state->champ[i];
		}
	}
	if (living == 0)
		error_exit(state, "\x1b[35mDraw, No Lives Reported\n\x1b[0m");
	if (living == 1)
	{
		ft_putstr(winner.champ_name);
		error_exit(state, "\x1b[35mWon!\n\x1b[0m");
	}
	if (living > 1 && state->cycles_to_die > CYCLE_TO_DIE)
		error_exit(state, "\x1b[35mDraw - Multiple champ Still ALive\n\x1b[0m");
}

void			run_champs(t_state *state)
{
	int			i;
	t_process	*temp;

	i = 4;
	while (--i > -1)
	{
		if (state->champ[i])
		{
			temp = state->champ[i];
			complete_op1(state, temp);
			complete_op2(state, temp);
			while (temp->next && temp->ops_executed < temp->next->ops_executed)
			{
				temp = temp->next;
				complete_op1(state, temp);
				complete_op2(state, temp);
			}
			start_op1(temp);
			start_op2(temp);
		}
	}
}

void			check_nbr_live(t_state *state)
{
	int			i;
	int			found;
	t_process	*temp;

	i = -1;
	found = 0;
	while (++i < 4)
	{
		temp = state->champ[i];
		while (temp)
		{
			if (temp->alive >= NBR_LIVE)
				found++;
			temp->alive = 0;
			temp = temp->next;
		}
	}
	if (found > 0)
		state->cycles_to_die -= CYCLE_DELTA;
}
