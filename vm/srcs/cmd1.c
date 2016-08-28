#include <vm.h>

void			live(t_state *state, t_process *process)
{
	process->alive++;
	if (process->current_op.arg1 < 5 && process->current_op.arg1 > 0)
		state->live_champs[process->current_op.arg1 - 1] = 1;
}

void			ld(t_process *process)
{
	if (process->current_op.arg2 < 17 && process->current_op.arg2 > 0)
	{
		process->registries[process->current_op.arg2] = 
			process->current_op.arg1;
		process->carry = 1;
	}
	else
		process->carry = 0;
}

/*112 120 124 - acb implies a registry, indirect, any
    80  84  92 - acb implies a registry, registry, any*/

void		 	st(t_process *process)
{
    t_address   *indirect;
	//if instruction, address = PC + (arg2 % IDX_MOD) / 5
	//field at instruction to be changed is remainder
	if (process->current_op.arg1 < 17 && process->current_op.arg1 > 0)
	{
		if (process->current_op.acb <= 112 && process->current_op.acb >= 124)
        {
            while (indirect->address != process->pc->address
        }
        if (process->current_op.acb <= 80 && process->current_op.acb >= 92)
        {

        }
	}
}

void			add(t_process *process)
{
	(void)process;
}

void			sub(t_process *process)
{
	(void)process;

}
