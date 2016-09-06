/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaunder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 12:50:09 by bsaunder          #+#    #+#             */
/*   Updated: 2016/09/06 14:08:12 by bsaunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void			sti(t_state *state, t_process *process)
{
	if ((ACB & 0x50) == 0x50)
		edit_field(state, PC, (REG[ARG2] + REG[ARG3]) % IDX_MOD, REG[ARG1]);
	else if ((ACB & 0x5C) == 0x5C)
		edit_field(state, PC, (REG[ARG2] + ARG3) % IDX_MOD, REG[ARG1]);
	else if ((ACB & 0x5C) == 0x5C)
		edit_field(state, PC, 
				(REG[ARG2] + return_field(state, PC, ARG3)) % IDX_MOD, REG[ARG1]);
	else if ((ACB & 0x60) == 0x60)
		edit_field(state, PC, (ARG2 + REG[ARG3]) % IDX_MOD, REG[ARG1]);
	else if ((ACB & 0x6C) == 0x6C)
		edit_field(state, PC, (ARG2 + ARG3) % IDX_MOD, REG[ARG1]);
	else if ((ACB & 0x6C) == 0x6C)
		edit_field(state, PC, 
				(ARG2 + return_field(state, PC, ARG3)) % IDX_MOD, REG[ARG1]);
	else if ((ACB & 0x70) == 0x70)
		edit_field(state, PC, 
				(return_field(state, PC, ARG2) + REG[ARG3]) % IDX_MOD, REG[ARG1]);
	else if ((ACB & 0x7C) == 0x7C)
		edit_field(state, PC, (return_field(state, PC, ARG2) + ARG3) % IDX_MOD, REG[ARG1]);
	else if ((ACB & 0x7C) == 0x7C)
		edit_field(state, PC, 
				(return_field(state, PC, ARG2) + return_field(state, PC, ARG3))
				% IDX_MOD, REG[ARG1]);
}	

void			cfork(t_state *state, t_process *process)
{
	t_process	*new;

	puts("in cfork...");
	create_process(state, process->champ_no, "NULL");
	new = process;
	while (new->next)
		new = new->next;
	new->champ_name = process->champ_name;
	new->champ_comment = process->champ_comment;
	new->carry = process->carry;
	new->pc = seek_address(state, PC, (PC->address + ARG2) % IDX_MOD);
}	

void			lld(t_state *state, t_process *process)
{
	process->carry = 1;
	if ((ACB & 0x50) == 0x50) //REG REG
		REG[ARG3] = return_field(state, PC, (REG[ARG1] + REG[ARG2]));
	else if ((ACB & 0x90) == 0x90) //DIR REG
		REG[ARG3] = return_field(state, PC, (REG[ARG1] + ARG2));
	else if ((ACB & 0xD0) == 0xD0) //IND REG
		REG[ARG3] = return_field(state, PC,
				(REG[ARG1] + return_field(state, PC, ARG2)));
	else
		process->carry = 0;
}	

void			lldi(t_state *state, t_process *process)
{
	process->carry = 1;
	if ((ACB & 0x50) == 0x50)
		REG[ARG3] = return_field(state, PC, (REG[ARG1] + REG[ARG2]));
	else if ((ACB & 0xD0) == 0xD0)
		REG[ARG3] = return_field(state, PC, (REG[ARG1] + ARG2));
	else if ((ACB & 0x90) == 0x90)
		REG[ARG3] = return_field(state, PC,
				(REG[ARG1] + return_field(state, PC, ARG2)));
	else if ((ACB & 0x70) == 0x70)
		REG[ARG3] = return_field(state, PC, (ARG1 + REG[ARG2]));
	else if ((ACB & 0xF0) == 0xF0)
		REG[ARG3] = return_field(state, PC, (ARG1 + ARG2));
	else if ((ACB & 0xB0) == 0xB0)
		REG[ARG3] = return_field(state, PC, (ARG1 + return_field(state, PC, ARG2)));
	else if ((ACB & 0x90) == 0x90)
		REG[ARG3] = return_field(state, PC,
				(return_field(state, PC, ARG1) + REG[ARG2]));
	else if ((ACB & 0xD0) == 0xD0)
		REG[ARG3] = return_field(state, PC, (return_field(state, PC, ARG1) + ARG2));
	else if ((ACB & 0x50) == 0x50)
		REG[ARG3] = return_field(state, PC,
				return_field(state, PC, ARG1) +
				return_field(state, PC, ARG1));
	else
		process->carry = 0;
}	

void			lfork(t_state *state, t_process *process)
{
	t_process	*new;

	create_process(state, process->champ_no, "NULL");
	new = process;
	while (new->next)
		new = new->next;
	new->champ_name = process->champ_name;
	new->champ_comment = process->champ_comment;
	new->carry = process->carry;
	new->pc = seek_address(state, PC, (PC->address + ARG2));
}	
