#include <vm.h>

void			sti(t_process *process)
{
    if (ACB - 4 == 168) //REG REG
		edit_field(PC, (REG[ARG2] + REG[ARG3]) % IDX_MOD, REG[ARG1]);
    else if (ACB - 4 == 164) //REG DIR
		edit_field(PC, (REG[ARG2] + ARG3) % IDX_MOD, REG[ARG1]);
    else if (ACB - 4 == 172) //REG IND
		edit_field(PC, 
				(REG[ARG2] + return_field(PC, ARG3)) % IDX_MOD, REG[ARG1]);
    else if (ACB - 4 == 152) //DIR REG
		edit_field(PC, (ARG2 + REG[ARG3]) % IDX_MOD, REG[ARG1]);
    else if (ACB - 4 == 148) //DIR DIR
		edit_field(PC, (ARG2 + ARG3) % IDX_MOD, REG[ARG1]);
    else if (ACB - 4 == 156) //DIR IND
		edit_field(PC, 
				(ARG2 + return_field(PC, ARG3)) % IDX_MOD, REG[ARG1]);
    else if (ACB - 4 == 184)  //IND REG
		edit_field(PC, 
				(return_field(PC, ARG2) + REG[ARG3]) % IDX_MOD, REG[ARG1]);
    else if (ACB - 4 == 180) //IND DIR
		edit_field(PC, (return_field(PC, ARG2) + ARG3) % IDX_MOD, REG[ARG1]);
    else if (ACB - 4 == 188) //IND IND
		edit_field(PC, 
				(return_field(PC, ARG2) + return_field(PC, ARG3))
			   	% IDX_MOD, REG[ARG1]);
}	

void			cfork(t_state *state, t_process *process)
{
    t_process	*new;

	create_process(state, process->champ_no);
	new = process;
	while (new->next)
		new = new->next;
	new->champ_name = process->champ_name;
	new->champ_comment = process->champ_comment;
	new->carry = process->carry;
	new->pc = seek_address(PC, (PC->address + ARG2) % IDX_MOD);
}	

void			lld(t_process *process)
{
    process->carry = 1;
    if ((ACB & 160) == 160) //REG REG
        REG[ARG3] = return_field(PC, (REG[ARG1] + REG[ARG2]));
    else if ((ACB & 96) == 96) //DIR REG
        REG[ARG3] = return_field(PC, (REG[ARG1] + ARG2));
    else if ((ACB & 224) == 224) //IND REG
        REG[ARG3] = return_field(PC,
                (REG[ARG1] + return_field(PC, ARG2)));
    else
        process->carry = 0;
}	

void			lldi(t_process *process)
{
	process->carry = 1;
    if (ACB - 4 >= 80) //REG REG
        REG[ARG3] = return_field(PC, (REG[ARG1] + REG[ARG2]));
    else if (ACB - 4 >= 208) //REG DIR
        REG[ARG3] = return_field(PC, (REG[ARG1] + ARG2));
    else if (ACB - 4 >= 144) //REG IND
        REG[ARG3] = return_field(PC,
                (REG[ARG1] + return_field(PC, ARG2)));
    else if (ACB - 4 >= 112) //DIR REG
        REG[ARG3] = return_field(PC, (ARG1 + REG[ARG2]));
    else if (ACB - 4 >= 240) //DIR DIR
        REG[ARG3] = return_field(PC, (ARG1 + ARG2));
    else if (ACB - 4 >= 176) //DIR IND
        REG[ARG3] = return_field(PC, (ARG1 + return_field(PC, ARG2)));
    else if (ACB - 4 >= 96)  //IND REG
        REG[ARG3] = return_field(PC,
                (return_field(PC, ARG1) + REG[ARG2]));
    else if (ACB - 4 >= 224) //IND DIR
        REG[ARG3] = return_field(PC, (return_field(PC, ARG1) + ARG2));
    else if (ACB - 4 >= 160) //IND IND
        REG[ARG3] = return_field(PC,
                return_field(PC, ARG1) +
                return_field(PC, ARG1));
	else
		process->carry = 0;
}	

void			lfork(t_state *state, t_process *process)
{
    t_process	*new;

	create_process(state, process->champ_no);
	new = process;
	while (new->next)
		new = new->next;
	new->champ_name = process->champ_name;
	new->champ_comment = process->champ_comment;
	new->carry = process->carry;
	new->pc = seek_address(PC, (PC->address + ARG2));
}	
