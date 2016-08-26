#include <vm.h>

void			start_op1(t_process *process)
{
	if (process->current_op.operation == 0)
		;
	else if (process->current_op.operation == 1)
		set_op(process, 10);
	else if (process->current_op.operation == 2)
		set_op(process, 5);
	else if (process->current_op.operation == 3)
		set_op(process, 5);
	else if (process->current_op.operation == 4)
		set_op(process, 10);
	else if (process->current_op.operation == 5)
		set_op(process, 10);
	else if (process->current_op.operation == 6)
		set_op(process, 6);
	else if (process->current_op.operation == 7)
		set_op(process, 6);
}

void			start_op2(t_process *process)
{
	if (process->current_op.operation == 8)
		set_op(process, 6);
	else if (process->current_op.operation == 9)
		set_op(process, 20);
	else if (process->current_op.operation == 10)
		set_op(process, 25);
	else if (process->current_op.operation == 11)
		set_op(process, 25);
	else if (process->current_op.operation == 12)
		set_op(process, 800);
	else if (process->current_op.operation == 13)
		set_op(process, 10);
	else if (process->current_op.operation == 14)
		set_op(process, 50);
	else if (process->current_op.operation == 15)
		set_op(process, 1000);
	else if (process->current_op.operation == 16)
		set_op(process, 2);
}

void			set_op(t_process *process, int cycle_cost)
{
	process->cycles_to_execute = cycle_cost;
	process->current_op = *process->pc;
}

void			complete_op1(t_process *process)
{
	if (process->cycles_to_execute == 0)
	{
		if (process->current_op.operation == 0)
			;
		else if (process->current_op.operation == 1)
			live(process);
		else if (process->current_op.operation == 2)
			ld(process);
		else if (process->current_op.operation == 3)
			st(process);
		else if (process->current_op.operation == 4)
			add(process);
		else if (process->current_op.operation == 5)
			sub(process);
		else if (process->current_op.operation == 6)
			and(process);
		else if (process->current_op.operation == 7)
			or(process);
	}
	else
		process->cycles_to_execute--;
}

void			complete_op2(t_process *process)
{
	if (process->cycles_to_execute == 0)
	{
		if (process->current_op.operation == 8)
			xor(process);
		else if (process->current_op.operation == 9)
			zjmp(process);
		else if (process->current_op.operation == 10)
			ldi(process);
		else if (process->current_op.operation == 11)
			sti(process);
		else if (process->current_op.operation == 12)
			cfork(process);
		else if (process->current_op.operation == 13)
			lld(process);
		else if (process->current_op.operation == 14)
			lldi(process);
		else if (process->current_op.operation == 15)
			lfork(process);
		else if (process->current_op.operation == 16)
			aff(process);
	}
	else
		process->cycles_to_execute--;	
}
