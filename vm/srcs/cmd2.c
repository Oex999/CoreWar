#include <vm.h>

void			and(t_process *process)
{
    process->carry = 1;
    if (ACB - 4 >= 80) //REG REG
        REG[ARG3] = REG[ARG1] & REG[ARG2];
    else if (ACB - 4 >= 208) //REG DIR
        REG[ARG3] = REG[ARG1] & ARG2;
    else if (ACB - 4 >= 144) //REG IND
        REG[ARG3] = REG[ARG1] &
            return_field(seek_address(PC ,ARG2 % IDX_MOD), ARG2 % 5);
    else if (ACB - 4 >= 112) //DIR REG
        REG[ARG3] = ARG1 & REG[ARG2];
    else if (ACB - 4 >= 240) //DIR DIR
        REG[ARG3] = ARG1 & ARG2;
    else if (ACB - 4 >= 176) //DIR IND
        REG[ARG3] = ARG1 & 
            return_field(seek_address(PC ,ARG2 % IDX_MOD), ARG2 % 5);
    else if (ACB - 4 >= 96)  //IND REG
        REG[ARG3] = 
            return_field((seek_address(PC, ARG1 % IDX_MOD)), ARG1 % 5) &
            REG[ARG2];
    else if (ACB - 4 >= 224) //IND DIR
        REG[ARG3] = 
            return_field((seek_address(PC, ARG1 % IDX_MOD)), ARG1 % 5) & ARG2;
    else if (ACB - 4 >= 160) //IND IND
        REG[ARG3] = 
            return_field((seek_address(PC, ARG1 % IDX_MOD)), ARG1 % 5) & 
            return_field((seek_address(PC, ARG2 % IDX_MOD)), ARG2 % 5);
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
        REG[ARG3] = REG[ARG1] |
            return_field(seek_address(PC ,ARG2 % IDX_MOD), ARG2 % 5);
    else if (ACB - 4 >= 112) //DIR REG
        REG[ARG3] = ARG1 |REG[ARG2];
    else if (ACB - 4 >= 240) //DIR DIR
        REG[ARG3] = ARG1 |ARG2;
    else if (ACB - 4 >= 176) //DIR IND
        REG[ARG3] = ARG1 |
            return_field(seek_address(PC ,ARG2 % IDX_MOD), ARG2 % 5);
    else if (ACB - 4 >= 96)  //IND REG
        REG[ARG3] = 
            return_field((seek_address(PC, ARG1 % IDX_MOD)), ARG1 % 5) |
            REG[ARG2];
    else if (ACB - 4 >= 224) //IND DIR
        REG[ARG3] = 
            return_field((seek_address(PC, ARG1 % IDX_MOD)), ARG1 % 5) | ARG2;
    else if (ACB - 4 >= 160) //IND IND
        REG[ARG3] = 
            return_field((seek_address(PC, ARG1 % IDX_MOD)), ARG1 % 5) | 
            return_field((seek_address(PC, ARG2 % IDX_MOD)), ARG2 % 5);
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
        REG[ARG3] = REG[ARG1] ^
            return_field(seek_address(PC ,ARG2 % IDX_MOD), ARG2 % 5);
    else if (ACB - 4 >= 112) //DIR REG
        REG[ARG3] = ARG1 ^ REG[ARG2];
    else if (ACB - 4 >= 240) //DIR DIR
        REG[ARG3] = ARG1 ^ ARG2;
    else if (ACB - 4 >= 176) //DIR IND
        REG[ARG3] = ARG1 ^ 
            return_field(seek_address(PC ,ARG2 % IDX_MOD), ARG2 % 5);
    else if (ACB - 4 >= 96)  //IND REG
        REG[ARG3] = 
            return_field((seek_address(PC, ARG1 % IDX_MOD)), ARG1 % 5) ^
            REG[ARG2];
    else if (ACB - 4 >= 224) //IND DIR
        REG[ARG3] = 
            return_field((seek_address(PC, ARG1 % IDX_MOD)), ARG1 % 5) ^ ARG2;
    else if (ACB - 4 >= 160) //IND IND
        REG[ARG3] = 
            return_field((seek_address(PC, ARG1 % IDX_MOD)), ARG1 % 5) ^ 
            return_field((seek_address(PC, ARG2 % IDX_MOD)), ARG2 % 5);
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
    int         address;
    int         result;

    if (ACB - 4 >= 80) //REG REG
    {
        address = seek_address(PC, REG[ARG1] + REG[ARG2]);
        REG[ARG3] = return_field(address, REG[ARG1] + REG[ARG2]);
    }
    else if (ACB - 4 >= 208) //REG DIR
    {
        address = seek_address(PC, REG[ARG1] + ARG2);
        REG[ARG3] = return_field(address, REG[ARG1] + ARG2);
    }
    else if (ACB - 4 >= 144) //REG IND
    {
        result = return_field(seek_address(PC, ARG1), ARG1)
            + return_field(seek_address(PC, ARG2), ARG2);
        address = seek_address(PC, result);
        REG[ARG3] = return_field(address, result);
    }
    else if (ACB - 4 >= 112) //DIR REG
    {
        address = seek_address(PC, ARG1 + REG[ARG2]);
        REG[ARG3] = return_field(address, ARG1 + REG[ARG2] % 5);
    }
    else if (ACB - 4 >= 240) //DIR DIR
    {
        address = seek_address(PC, ARG1 + ARG2);
        REG[ARG3] = return_field(address, ARG1 + ARG2 % 5);
    }
    else if (ACB - 4 >= 176) //DIR IND
    {
        result = return_field(seek_address(PC, ARG2), ARG2);
        address = seek_address(PC, ARG1 + result);
        REG[ARG3] = return_field(address, ARG1 + result);
    }
    else if (ACB - 4 >= 96)  //IND REG
    {
        result = return_field(seek_address(PC, ARG1), ARG1);
        address = seek_address(PC, result + REG[ARG2]);
        REG[ARG3] = return_field(address, result + REG[ARG2]);
    }
    else if (ACB - 4 >= 224) //IND DIR
    {
        result = return_field(seek_address(PC, ARG1), ARG1);
        address = seek_address(PC, result + ARG2);
        REG[ARG3] = return_field(address, result + ARG2);
    }
    else if (ACB - 4 >= 160) //IND IND
    {
        result = return_field(seek_address(PC, ARG1), ARG1) 
            + return_field(seek_address(PC, ARG2), ARG2);
        address = seek_address(PC, result);
        REG[ARG3] = return_field(address, result);
    }
}
