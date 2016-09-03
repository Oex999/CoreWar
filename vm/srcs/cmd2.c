#include <vm.h>

void			and(t_state *state, t_process *process)
{
	process->carry = 1;
	if ((ACB & 0x50) == 0x50) //REG REG
		REG[ARG3] = REG[ARG1] & REG[ARG2];
	else if ((ACB & 0x60) == 0x60) //REG DIR
		REG[ARG3] = REG[ARG1] & ARG2;
	else if ((ACB & 0x70) == 0x70) //REG IND
		REG[ARG3] = REG[ARG1] & return_field(state, PC, ARG2 % IDX_MOD);
	else if ((ACB & 0x90) == 0x90) //DIR REG
		REG[ARG3] = ARG1 & REG[ARG2];
	else if ((ACB & 0xA0) == 0xA0) //DIR DIR
		REG[ARG3] = ARG1 & ARG2;
	else if ((ACB & 0xB0) == 0xB0) //DIR IND
		REG[ARG3] = ARG1 & return_field(state, PC ,ARG2 % IDX_MOD);
	else if ((ACB & 0xD0) == 0xD0)  //IND REG
		REG[ARG3] = return_field(state, PC, ARG1 % IDX_MOD) & REG[ARG2];
	else if ((ACB & 0xE0) == 0xE0) //IND DIR
		REG[ARG3] = return_field(state, PC, ARG1 % IDX_MOD) & ARG2;
	else if ((ACB & 0xF0) == 0xF0) //IND IND
		REG[ARG3] = 
			return_field(state ,PC, ARG1 % IDX_MOD) & return_field(state, PC, ARG2 % IDX_MOD);
	else
		process->carry = 0;
}

void			or(t_state *state, t_process *process)
{
	process->carry = 1;
	if ((ACB & 0x50) == 0x50) //REG REG
		REG[ARG3] = REG[ARG1] | REG[ARG2];
	else if ((ACB & 0x60) == 0x60) //REG DIR
		REG[ARG3] = REG[ARG1] | ARG2;
	else if ((ACB & 0x70) == 0x70) //REG IND
		REG[ARG3] = REG[ARG1] | return_field(state, PC ,ARG2 % IDX_MOD);
	else if ((ACB & 0x90) == 0x90) //DIR REG
		REG[ARG3] = ARG1 | REG[ARG2];
	else if ((ACB & 0xA0) == 0xA0) //DIR DIR
		REG[ARG3] = ARG1 | ARG2;
	else if ((ACB & 0xB0) == 0xB0) //DIR IND
		REG[ARG3] = ARG1 | return_field(state, PC, ARG2 % IDX_MOD);
	else if ((ACB & 0xD0) == 0xD0)  //IND REG
		REG[ARG3] = return_field(state, PC, ARG1 % IDX_MOD) | REG[ARG2];
	else if ((ACB & 0xE0) == 0xE0) //IND DIR
		REG[ARG3] = return_field(state, PC, ARG1 % IDX_MOD) | ARG2;
	else if ((ACB & 0xF0) == 0xF0) //IND IND
		REG[ARG3] = 
			return_field(state, PC, ARG1 % IDX_MOD) | return_field(state, PC, ARG2 % IDX_MOD);
	else
		process->carry = 0;
}

void			xor(t_state *state, t_process *process)
{
	process->carry = 1;
	if ((ACB & 0x50) == 0x50) //REG REG
		REG[ARG3] = REG[ARG1] ^ REG[ARG2];
	else if ((ACB & 0x60) == 0x60) //REG DIR
		REG[ARG3] = REG[ARG1] ^ ARG2;
	else if ((ACB & 0x70) == 0x70) //REG IND
		REG[ARG3] = REG[ARG1] ^ return_field(state, PC, ARG2 % IDX_MOD);
	else if ((ACB & 0x90) == 0x90) //DIR REG
		REG[ARG3] = ARG1 ^ REG[ARG2];
	else if ((ACB & 0xA0) == 0xA0) //DIR DIR
		REG[ARG3] = ARG1 ^ ARG2;
	else if ((ACB & 0xB0) == 0xB0) //DIR IND
		REG[ARG3] = ARG1 ^ return_field(state, PC, ARG2 % IDX_MOD);
	else if ((ACB & 0xD0) == 0xD0)  //IND REG
		REG[ARG3] = return_field(state, PC, ARG1 % IDX_MOD) ^ REG[ARG2];
	else if ((ACB & 0xE0) == 0xE0) //IND DIR
		REG[ARG3] = return_field(state, PC, ARG1 % IDX_MOD) ^ ARG2;
	else if ((ACB & 0xF0) == 0xF0) //IND IND
		REG[ARG3] = 
			return_field(state, PC, ARG1 % IDX_MOD) ^ return_field(state, PC, ARG2 % IDX_MOD);
	else
		process->carry = 0;
}

void			zjmp(t_state *state, t_process *process)
{
	if (process->carry == 1)
		PC = seek_address(state, PC, return_field(state, PC, ARG1 % IDX_MOD));
}

void			ldi(t_state *state, t_process *process)
{
	if ((ACB & 0x50) == 0x50) //REG REG
		REG[ARG3] = return_field(state, PC, (REG[ARG1] + REG[ARG2]) % IDX_MOD);
	else if ((ACB & 0x60) == 0x60) //REG DIR
		REG[ARG3] = return_field(state, PC, (REG[ARG1] + ARG2) % IDX_MOD);
	else if ((ACB & 0x70) == 0x70) //REG IND
		REG[ARG3] = return_field(state, PC, 
				(REG[ARG1] + return_field(state, PC, ARG2)) % IDX_MOD);
	else if ((ACB & 0x90) == 0x90) //DIR REG
		REG[ARG3] = return_field(state, PC, (ARG1 + REG[ARG2]) % IDX_MOD);
	else if ((ACB & 0xA0) == 0xA0) //DIR DIR
		REG[ARG3] = return_field(state, PC, (ARG1 + ARG2) % IDX_MOD);
	else if ((ACB & 0xB0) == 0xB0) //DIR IND
		REG[ARG3] = return_field(state, PC, (ARG1 + return_field(state, PC, ARG2)) % IDX_MOD);
	else if ((ACB & 0xD0) == 0xD0)  //IND REG
		REG[ARG3] = return_field(state, PC, 
				(return_field(state, PC, ARG1) + REG[ARG2]) % IDX_MOD);
	else if ((ACB & 0xE0) == 0xE0) //IND DIR
		REG[ARG3] = return_field(state, PC, (return_field(state, PC, ARG1) + ARG2) % IDX_MOD);
	else if ((ACB & 0xF0) == 0xF0) //IND IND
		REG[ARG3] = return_field(state, PC, 
				(return_field(state, PC, ARG1) + 
				return_field(state, PC, ARG1)) % IDX_MOD);
}
