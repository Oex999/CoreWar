#include <vm.h>

void			live(t_state *state, t_process *process)
{
	process->alive++;
	if (ARG1 < 5 && ARG1 > 0)
		state->live_champs[ARG1 - 1] = 1;
}

void			ld(t_process *process)
{
	process->carry = 1;
	if ((ACB & 160) == 160) //REG REG
        REG[ARG3] = return_field(PC, (REG[ARG1] + REG[ARG2]) % IDX_MOD);
    else if ((ACB & 96) == 96) //DIR REG
        REG[ARG3] = return_field(PC, (REG[ARG1] + ARG2) % IDX_MOD);
    else if ((ACB & 224) == 224) //IND REG
        REG[ARG3] = return_field(PC,
                (REG[ARG1] + return_field(PC, ARG2)) % IDX_MOD);
	else
		process->carry = 0;
}

/*112 120 124 - acb implies a registry, indirect, any
    80  84  92 - acb implies a registry, registry, any*/

void		 	st(t_process *process)
{
    t_address   *indirect;
    int         reg;
	
    if (ARG1 < 17 && ARG1 > 0)
	{
        reg = ARG1;
		if (ACB <= 112 && ACB >= 124)
        {
            indirect = PC;
            while (indirect->address != (PC->address + 
                        (ARG2 % IDX_MOD) / 5) % MEM_SIZE)
                indirect = indirect->next;
            if (ARG2 % 5 == 0)
                indirect->operation = REG[reg];
            if (ARG2 % 5 == 1)
                indirect->acb = REG[reg];
            if (ARG2 % 5 == 2)
                indirect->arg1 = REG[reg];
            if (ARG2 % 5 == 3)
                indirect->arg2 = REG[reg];
            if (ARG2 % 5 == 4)
                indirect->arg3 = REG[reg];
        }
        if (ACB <= 80 && ACB >= 92)
            if (ARG2 < 17 && ARG2 > 0)
                REG[ARG2] =
                    REG[reg];
	}
}

/*3 registry coding bte = 84*/

void			add(t_process *process)
{
    if (ACB == 84)
    {
        if (ARG1 < 17 && ARG1 > 0)
            if (ARG2 < 17 && ARG2 > 0)
                if (ARG3 < 17 && 
                        ARG3 > 0)    
                {
                    ARG3 = 
                        ARG1 + ARG2;
                    process->carry = 1;
                }
    }
    else
        process->carry = 0;
}

void			sub(t_process *process)
{
    if (ACB == 84)
    {
        if (ARG1 < 17 && ARG1 > 0)
            if (ARG2 < 17 && ARG2 > 0)
                if (ARG3 < 17 && 
                        ARG3 > 0)    
                {
                    ARG3 = 
                        ARG1 - ARG2;
                    process->carry = 1;
                }
    }
    else
        process->carry = 0;
}
