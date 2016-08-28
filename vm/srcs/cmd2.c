#include <vm.h>

void			and(t_process *process)
{
    process->carry = 1;
    if (process->current_op.acb - 4 >= 80) //REG REG
        process->registries[process->current_op.arg3] = 
            process->registries[process->current_op.arg1] & 
            process->registries[process->current_op.arg2];
    else if (process->current_op.acb - 4 >= 208) //REG DIR
        process->registries[process->current_op.arg3] = 
            process->registries[process->current_op.arg1] & 
            process->current_op.arg2;
    else if (process->current_op.acb - 4 >= 144) //REG IND
        process->registries[process->current_op.arg3] = 
            process->registries[process->current_op.arg1] &
            return_field(seek_address(process->pc ,process->current_op.arg2 % IX_MOD), process->current_op.arg2 % 5);
    else if (process->current_op.acb - 4 >= 112) //DIR REG
        process->registries[process->current_op.arg3] = 
            process->current_op.arg1 & 
            process->registries[process->current_op.arg2];
    else if (process->current_op.acb - 4 >= 240) //DIR DIR
        process->registries[process->current_op.arg3] = 
            process->current_op.arg1 & 
            process->current_op.arg2;
    else if (process->current_op.acb - 4 >= 176) //DIR IND
        process->registries[process->current_op.arg3] = 
            process->current_op.arg1 & 
            return_field(seek_address(process->pc ,process->current_op.arg2 % IDX_MOD), process->current_op.arg2 % 5);
    else if (process->current_op.acb - 4 >= 96)  //IND REG
        process->registries[process->current_op.arg3] = 
            return_field((seek_address(process->pc, process->current_op.arg1 % IDX_MOD)), process->current_op.arg1 % 5) &
            process->registries[process->current_op.arg2];
    else if (process->current_op.acb - 4 >= 224) //IND DIR
        process->registries[process->current_op.arg3] = 
            return_field((seek_address(process->pc, process->current_op.arg1 % IDX_MOD)), process->current_op.arg1 % 5) &
            process->current_op.arg2;
    else if (process->current_op.acb - 4 >= 160) //IND IND
        process->registries[process->current_op.arg3] = 
            return_field((seek_address(process->pc, process->current_op.arg1 % IDX_MOD)), process->current_op.arg1 % 5) & 
            return_field((seek_address(process->pc, process->current_op.arg2 % IDX_MOD)), process->current_op.arg2 % 5)
    else
        process->carry = 0;
}

void			or(t_process *process)
{
    process->carry = 1;
    if (process->current_op.acb - 4 >= 80) //REG REG
        process->registries[process->current_op.arg3] = 
            process->registries[process->current_op.arg1] | 
            process->registries[process->current_op.arg2];
    else if (process->current_op.acb - 4 >= 208) //REG DIR
        process->registries[process->current_op.arg3] = 
            process->registries[process->current_op.arg1] | 
            process->current_op.arg2;
    else if (process->current_op.acb - 4 >= 144) //REG IND
        process->registries[process->current_op.arg3] = 
            process->registries[process->current_op.arg1] |
            return_field(seek_address(process->pc ,process->current_op.arg2 % IDX_MOD), process->current_op.arg2 % 5);
    else if (process->current_op.acb - 4 >= 112) //DIR REG
        process->registries[process->current_op.arg3] = 
            process->current_op.arg1 |
            process->registries[process->current_op.arg2];
    else if (process->current_op.acb - 4 >= 240) //DIR DIR
        process->registries[process->current_op.arg3] = 
            process->current_op.arg1 |
            process->current_op.arg2;
    else if (process->current_op.acb - 4 >= 176) //DIR IND
        process->registries[process->current_op.arg3] = 
            process->current_op.arg1 |
            return_field(seek_address(process->pc ,process->current_op.arg2 % IDX_MOD), process->current_op.arg2 % 5);
    else if (process->current_op.acb - 4 >= 96)  //IND REG
        process->registries[process->current_op.arg3] = 
            return_field((seek_address(process->pc, process->current_op.arg1 % IDX_MOD)), process->current_op.arg1 % 5) |
            process->registries[process->current_op.arg2];
    else if (process->current_op.acb - 4 >= 224) //IND DIR
        process->registries[process->current_op.arg3] = 
            return_field((seek_address(process->pc, process->current_op.arg1 % IDX_MOD)), process->current_op.arg1 % 5) |
            process->current_op.arg2;
    else if (process->current_op.acb - 4 >= 160) //IND IND
        process->registries[process->current_op.arg3] = 
            return_field((seek_address(process->pc, process->current_op.arg1 % IDX_MOD)), process->current_op.arg1 % 5) | 
            return_field((seek_address(process->pc, process->current_op.arg2 % IDX_MOD)), process->current_op.arg2 % 5)
    else
        process->carry = 0;
}

void			xor(t_process *process)
{
    process->carry = 1;
    if (process->current_op.acb - 4 >= 80) //REG REG
        process->registries[process->current_op.arg3] = 
            process->registries[process->current_op.arg1] ^
            process->registries[process->current_op.arg2];
    else if (process->current_op.acb - 4 >= 208) //REG DIR
        process->registries[process->current_op.arg3] = 
            process->registries[process->current_op.arg1] ^ 
            process->current_op.arg2;
    else if (process->current_op.acb - 4 >= 144) //REG IND
        process->registries[process->current_op.arg3] = 
            process->registries[process->current_op.arg1] ^
            return_field(seek_address(process->pc ,process->current_op.arg2 % IDX_MOD), process->current_op.arg2 % 5);
    else if (process->current_op.acb - 4 >= 112) //DIR REG
        process->registries[process->current_op.arg3] = 
            process->current_op.arg1 ^
            process->registries[process->current_op.arg2];
    else if (process->current_op.acb - 4 >= 240) //DIR DIR
        process->registries[process->current_op.arg3] = 
            process->current_op.arg1 ^ 
            process->current_op.arg2;
    else if (process->current_op.acb - 4 >= 176) //DIR IND
        process->registries[process->current_op.arg3] = 
            process->current_op.arg1 ^ 
            return_field(seek_address(process->pc ,process->current_op.arg2 % IDX_MOD), process->current_op.arg2 % 5);
    else if (process->current_op.acb - 4 >= 96)  //IND REG
        process->registries[process->current_op.arg3] = 
            return_field((seek_address(process->pc, process->current_op.arg1 % IDX_MOD)), process->current_op.arg1 % 5) ^
            process->registries[process->current_op.arg2];
    else if (process->current_op.acb - 4 >= 224) //IND DIR
        process->registries[process->current_op.arg3] = 
            return_field((seek_address(process->pc, process->current_op.arg1 % IDX_MOD)), process->current_op.arg1 % 5) ^
            process->current_op.arg2;
    else if (process->current_op.acb - 4 >= 160) //IND IND
        process->registries[process->current_op.arg3] = 
            return_field((seek_address(process->pc, process->current_op.arg1 % IDX_MOD)), process->current_op.arg1 % 5) ^ 
            return_field((seek_address(process->pc, process->current_op.arg2 % IDX_MOD)), process->current_op.arg2 % 5)
    else
        process->carry = 0;
}

void			zjmp(t_process *process)
{
    if (process->carry = 1)
        process->pc = find_address(process->pc, process->current_op.arg1 % IDX_MOD);
}

void			ldi(t_process *process)
{
	(void)process;

}
