/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaunder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 12:32:01 by bsaunder          #+#    #+#             */
/*   Updated: 2016/09/06 14:05:21 by bsaunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void			live(t_state *state, t_process *process)
{
	process->alive++;
	if (ARG1 < 5 && ARG1 > 0)
		state->live_champs[ARG1 - 1] = 1;
}

void			ld(t_state *state, t_process *process)
{
	process->carry = 1;

	if ((ACB & 0x50) == 0x50)
		REG[ARG3] = return_field(state, PC, (REG[ARG1] + REG[ARG2]) % IDX_MOD);
	else if ((ACB & 0x90) == 0x90)
		REG[ARG3] = return_field(state, PC, (REG[ARG1] + ARG2) % IDX_MOD);
	else if ((ACB & 0xD0) == 0xD0)
		REG[ARG3] = return_field(state, PC, REG[ARG1] + return_field(state, PC, ARG2)) % IDX_MOD;
	else
		process->carry = 0;
}

void			st(t_process *process)
{
	t_address   *indirect;

	if (ARG1 < 17 && ARG1 > 0)
	{
		if ((ACB & 0x70) == 0x70)
		{
			indirect = PC;
			while (indirect->address != (PC->address +
						(ARG2 % IDX_MOD) / 5) % MEM_SIZE)
				indirect = indirect->next;
			if (ARG2 % 5 == 0)
				indirect->operation = REG[ARG1];
			if (ARG2 % 5 == 1)
				indirect->acb = REG[ARG1];
			if (ARG2 % 5 == 2)
				indirect->arg1 = REG[ARG1];
			if (ARG2 % 5 == 3)
				indirect->arg2 = REG[ARG1];
			if (ARG2 % 5 == 4)
				indirect->arg3 = REG[ARG1];
		}
		if ((ACB & 0x50) == 0x50)
			if (ARG2 < 17 && ARG2 > 0)
				REG[ARG2] = REG[ARG1];
	}
}

void			add(t_process *process)
{
	if ((ACB & 0x50) == 0x50)
	{
		if (ARG1 < 17 && ARG1 > 0)
			if (ARG2 < 17 && ARG2 > 0)
				if (ARG3 < 17 && ARG3 > 0)
				{
					ARG3 = ARG1 + ARG2;
					process->carry = 1;
				}
	}
	else
		process->carry = 0;
}

void			sub(t_process *process)
{
	if ((ACB & 0x50) == 0x50)
	{
		if (ARG1 < 17 && ARG1 > 0)
			if (ARG2 < 17 && ARG2 > 0)
				if (ARG3 < 17 && ARG3 > 0)
				{
					ARG3 = ARG1 - ARG2;
					process->carry = 1;
				}
	}
	else
		process->carry = 0;
}
