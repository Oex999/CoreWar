#include <vm.h>

void			and(t_process *process)
{
    process->carry = 1;
    if (ACB - 4 >= 80) //REG REG
        REG[ARG3] = REG[ARG1] & REG[ARG2];
    else if (ACB - 4 >= 208) //REG DIR
        REG[ARG3] = REG[ARG1] & ARG2;
    else if (ACB - 4 >= 144) //REG IND
        REG[ARG3] = REG[ARG1] & return_field(PC, ARG2 % IDX_MOD);
    else if (ACB - 4 >= 112) //DIR REG
        REG[ARG3] = ARG1 & REG[ARG2];
    else if (ACB - 4 >= 240) //DIR DIR
        REG[ARG3] = ARG1 & ARG2;
    else if (ACB - 4 >= 176) //DIR IND
        REG[ARG3] = ARG1 & return_field(PC ,ARG2 % IDX_MOD);
    else if (ACB - 4 >= 96)  //IND REG
        REG[ARG3] = return_field(PC, ARG1 % IDX_MOD) & REG[ARG2];
    else if (ACB - 4 >= 224) //IND DIR
        REG[ARG3] = return_field(PC, ARG1 % IDX_MOD) & ARG2;
    else if (ACB - 4 >= 160) //IND IND
        REG[ARG3] = 
            return_field(PC, ARG1 % IDX_MOD) & return_field(PC, ARG2 % IDX_MOD);
    else
        process->carry = 0;
}

void			or(t_process *process)
{
    process->carry = 1;
    if (ACB - 4 >= 80) //REG REG
        REG[ARG3] = REG[ARG1] | REG[ARG2];
    else if (ACB - 4 >= 208) //REG DIR
        REG[ARG3] = REG[ARG1] | ARG2;
    else if (ACB - 4 >= 144) //REG IND
        REG[ARG3] = REG[ARG1] | return_field(PC ,ARG2 % IDX_MOD);
    else if (ACB - 4 >= 112) //DIR REG
        REG[ARG3] = ARG1 | REG[ARG2];
    else if (ACB - 4 >= 240) //DIR DIR
        REG[ARG3] = ARG1 | ARG2;
    else if (ACB - 4 >= 176) //DIR IND
        REG[ARG3] = ARG1 | return_field(PC, ARG2 % IDX_MOD);
    else if (ACB - 4 >= 96)  //IND REG
        REG[ARG3] = return_field(PC, ARG1 % IDX_MOD) | REG[ARG2];
    else if (ACB - 4 >= 224) //IND DIR
        REG[ARG3] = return_field(PC, ARG1 % IDX_MOD) | ARG2;
    else if (ACB - 4 >= 160) //IND IND
        REG[ARG3] = 
            return_field(PC, ARG1 % IDX_MOD) | return_field(PC, ARG2 % IDX_MOD);
    else
        process->carry = 0;
}

void			xor(t_process *process)
{
    process->carry = 1;
    if (ACB - 4 >= 80) //REG REG
        REG[ARG3] = REG[ARG1] ^ REG[ARG2];
    else if (ACB - 4 >= 208) //REG DIR
        REG[ARG3] = REG[ARG1] ^ ARG2;
    else if (ACB - 4 >= 144) //REG IND
        REG[ARG3] = REG[ARG1] ^ return_field(PC, ARG2 % IDX_MOD);
    else if (ACB - 4 >= 112) //DIR REG
        REG[ARG3] = ARG1 ^ REG[ARG2];
    else if (ACB - 4 >= 240) //DIR DIR
        REG[ARG3] = ARG1 ^ ARG2;
    else if (ACB - 4 >= 176) //DIR IND
        REG[ARG3] = ARG1 ^ return_field(PC, ARG2 % IDX_MOD);
    else if (ACB - 4 >= 96)  //IND REG
        REG[ARG3] = return_field(PC, ARG1 % IDX_MOD) ^ REG[ARG2];
    else if (ACB - 4 >= 224) //IND DIR
        REG[ARG3] = return_field(PC, ARG1 % IDX_MOD) ^ ARG2;
    else if (ACB - 4 >= 160) //IND IND
        REG[ARG3] = 
            return_field(PC, ARG1 % IDX_MOD) ^ return_field(PC, ARG2 % IDX_MOD);
    else
        process->carry = 0;
}

void			zjmp(t_process *process)
{
    if (process->carry == 1)
        PC = seek_address(PC, return_field(PC, ARG1 % IDX_MOD));
}

void			ldi(t_process *process)
{
    if (ACB - 4 >= 80) //REG REG
        REG[ARG3] = return_field(PC, (REG[ARG1] + REG[ARG2]) % IDX_MOD);
    else if (ACB - 4 >= 208) //REG DIR
        REG[ARG3] = return_field(PC, (REG[ARG1] + ARG2) % IDX_MOD);
    else if (ACB - 4 >= 144) //REG IND
        REG[ARG3] = return_field(PC, 
				(REG[ARG1] + return_field(PC, ARG2)) % IDX_MOD);
    else if (ACB - 4 >= 112) //DIR REG
        REG[ARG3] = return_field(PC, (ARG1 + REG[ARG2]) % IDX_MOD);
    else if (ACB - 4 >= 240) //DIR DIR
        REG[ARG3] = return_field(PC, (ARG1 + ARG2) % IDX_MOD);
    else if (ACB - 4 >= 176) //DIR IND
        REG[ARG3] = return_field(PC, (ARG1 + return_field(PC, ARG2)) % IDX_MOD);
    else if (ACB - 4 >= 96)  //IND REG
        REG[ARG3] = return_field(PC, 
				(return_field(PC, ARG1) + REG[ARG2]) % IDX_MOD);
    else if (ACB - 4 >= 224) //IND DIR
        REG[ARG3] = return_field(PC, (return_field(PC, ARG1) + ARG2) % IDX_MOD);
    else if (ACB - 4 >= 160) //IND IND
        REG[ARG3] = return_field(PC, 
				(return_field(PC, ARG1) + 
				return_field(PC, ARG1)) % IDX_MOD);
}
