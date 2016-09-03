#include <vm.h>

void			start_op1(t_process *process)
{
	if (process->current_op.operation == 0)
		;
	else if (process->current_op.operation == 0x01)
		set_op(process, 10);
	else if (process->current_op.operation == 0x02)
		set_op(process, 5);
	else if (process->current_op.operation == 0x03)
		set_op(process, 5);
	else if (process->current_op.operation == 0x04)
		set_op(process, 10);
	else if (process->current_op.operation == 0x05)
		set_op(process, 10);
	else if (process->current_op.operation == 0x06)
		set_op(process, 6);
	else if (process->current_op.operation == 0x07)
		set_op(process, 6);
}

void			start_op2(t_process *process)
{
	if (process->current_op.operation == 0x08)
		set_op(process, 6);
	else if (process->current_op.operation == 0x09)
		set_op(process, 20);
	else if (process->current_op.operation == 0x0a)
		set_op(process, 25);
	else if (process->current_op.operation == 0x0b)
		set_op(process, 25);
	else if (process->current_op.operation == 0x0c)
		set_op(process, 800);
	else if (process->current_op.operation == 0x0d)
		set_op(process, 10);
	else if (process->current_op.operation == 0x0e)
		set_op(process, 50);
	else if (process->current_op.operation == 0x0f)
		set_op(process, 1000);
	else if (process->current_op.operation == 0x10)
		set_op(process, 2);
}

void			set_op(t_process *process, int cycle_cost)
{
	process->cycles_to_execute = cycle_cost;
	process->current_op = *process->pc;
}

void			complete_op1(t_state *state, t_process *process)
{
	if (process->cycles_to_execute == 0)
	{
		if (process->current_op.operation == 0)
			;
		else if (process->current_op.operation == 1)
			live(state, process);
		else if (process->current_op.operation == 2)
			ld(state, process);
		else if (process->current_op.operation == 3)
			st(process);
		else if (process->current_op.operation == 4)
			add(process);
		else if (process->current_op.operation == 5)
			sub(process);
		else if (process->current_op.operation == 6)
			and(state, process);
		else if (process->current_op.operation == 7)
			or(state, process);
		process->pc = process->pc->next;
	}
	else
		process->cycles_to_execute--;
}

void			complete_op2(t_state *state, t_process *process)
{
	if (process->cycles_to_execute == 0)
	{
		if (process->current_op.operation == 8)
			xor(state, process);
		else if (process->current_op.operation == 9)
			zjmp(state, process);
		else if (process->current_op.operation == 10)
			ldi(state, process);
		else if (process->current_op.operation == 11)
			sti(state, process);
		else if (process->current_op.operation == 12)
			cfork(state, process);
		else if (process->current_op.operation == 13)
			lld(state, process);
		else if (process->current_op.operation == 14)
			lldi(state, process);
		else if (process->current_op.operation == 15)
			lfork(state, process);
		else if (process->current_op.operation == 16)
			aff(process);
		if (process->current_op.operation != 9)
			process->pc = process->pc->next;
	}
	else
		process->cycles_to_execute--;	
}
