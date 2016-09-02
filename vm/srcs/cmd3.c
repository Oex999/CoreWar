#include <vm.h>

void			sti(t_state *state, t_process *process)
{
    if ((ACB & 168) == 168) //REG REG
		edit_field(state, PC, (REG[ARG2] + REG[ARG3]) % IDX_MOD, REG[ARG1]);
    else if ((ACB & 164) == 164) //REG DIR
		edit_field(state, PC, (REG[ARG2] + ARG3) % IDX_MOD, REG[ARG1]);
    else if ((ACB & 172) == 172) //REG IND
		edit_field(state, PC, 
				(REG[ARG2] + return_field(state, PC, ARG3)) % IDX_MOD, REG[ARG1]);
    else if ((ACB & 152) == 152) //DIR REG
		edit_field(state, PC, (ARG2 + REG[ARG3]) % IDX_MOD, REG[ARG1]);
    else if ((ACB & 148) == 148) //DIR DIR
		edit_field(state, PC, (ARG2 + ARG3) % IDX_MOD, REG[ARG1]);
    else if ((ACB & 156) == 156) //DIR IND
		edit_field(state, PC, 
				(ARG2 + return_field(state, PC, ARG3)) % IDX_MOD, REG[ARG1]);
    else if ((ACB & 184) == 184)  //IND REG
		edit_field(state, PC, 
				(return_field(state, PC, ARG2) + REG[ARG3]) % IDX_MOD, REG[ARG1]);
    else if ((ACB & 180) == 180) //IND DIR
		edit_field(state, PC, (return_field(state, PC, ARG2) + ARG3) % IDX_MOD, REG[ARG1]);
    else if ((ACB & 188) == 188) //IND IND
		edit_field(state, PC, 
				(return_field(state, PC, ARG2) + return_field(state, PC, ARG3))
			   	% IDX_MOD, REG[ARG1]);
}	

void			cfork(t_state *state, t_process *process)
{
    t_process	*new;

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
    if ((ACB & 160) == 160) //REG REG
        REG[ARG3] = return_field(state, PC, (REG[ARG1] + REG[ARG2]));
    else if ((ACB & 96) == 96) //DIR REG
        REG[ARG3] = return_field(state, PC, (REG[ARG1] + ARG2));
    else if ((ACB & 224) == 224) //IND REG
        REG[ARG3] = return_field(state, PC,
                (REG[ARG1] + return_field(state, PC, ARG2)));
    else
        process->carry = 0;
}	

void			lldi(t_state *state, t_process *process)
{
	process->carry = 1;
    if ((ACB & 80) == 80) //REG REG
        REG[ARG3] = return_field(state, PC, (REG[ARG1] + REG[ARG2]));
    else if ((ACB & 208) == 208) //REG DIR
        REG[ARG3] = return_field(state, PC, (REG[ARG1] + ARG2));
    else if ((ACB & 144) == 144) //REG IND
        REG[ARG3] = return_field(state, PC,
                (REG[ARG1] + return_field(state, PC, ARG2)));
    else if ((ACB & 112) == 112) //DIR REG
        REG[ARG3] = return_field(state, PC, (ARG1 + REG[ARG2]));
    else if ((ACB & 240) == 240) //DIR DIR
        REG[ARG3] = return_field(state, PC, (ARG1 + ARG2));
    else if ((ACB & 176) == 176) //DIR IND
        REG[ARG3] = return_field(state, PC, (ARG1 + return_field(state, PC, ARG2)));
    else if ((ACB & 96) == 96)  //IND REG
        REG[ARG3] = return_field(state, PC,
                (return_field(state, PC, ARG1) + REG[ARG2]));
    else if ((ACB & 224) == 224) //IND DIR
        REG[ARG3] = return_field(state, PC, (return_field(state, PC, ARG1) + ARG2));
    else if ((ACB & 160) == 160) //IND IND
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
