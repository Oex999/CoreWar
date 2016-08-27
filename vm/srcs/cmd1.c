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

void		 	st(t_process *process)
{
	//According to ACB, either reference a registry or instruction for 2 arg
	//if instruction, address = PC + (arg2 % IDX_MOD) / 5
	//field at instruction to be changed
	if (process->current_op.arg1 < 17 && process->current_op.arg1 > 0)
	{
		//112 120 124 - implies a registry, indirect, any
		//80  84  92 - implies a registry, registry, any
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
