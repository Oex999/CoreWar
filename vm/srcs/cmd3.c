#include <vm.h>

void		sti(t_process *process)
{
    t_address	*address;
    int         result;
// EDIT ALL ACB NUMBERS for ARG3 & ARG1 creating place that ARG2 REG is put
    if (ACB - 4 == 168) //REG REG
    {
        address = seek_address(PC, REG[ARG2] + REG[ARG3]);
        address = seek_address(address, (REG[ARG2] + REG[ARG3]) % IDX_MOD);
		edit_field(address, (REG[ARG2] + REG[ARG3]) % IDX_MOD, REG[ARG1]);
    }
    else if (ACB - 4 == 164) //REG DIR
    {
        address = seek_address(PC, REG[ARG2] + ARG3);
        address = return_field(address, (REG[ARG2] + ARG3) % IDX_MOD);
    }
    else if (ACB - 4 == 172) //REG IND
    {
        result = return_field(seek_address(PC, ARG2), ARG2)
            + return_field(seek_address(PC, ARG3), ARG3);
        address = seek_address(PC, result % IDX_MOD);
        address = return_field(address, result % IDX_MOD);
    }
    else if (ACB - 4 == 152) //DIR REG
    {
        address = seek_address(PC, ARG2 + REG[ARG3]);
        address = return_field(address, (ARG2 + REG[ARG3]) % 5);
    }
    else if (ACB - 4 == 148) //DIR DIR
    {
        address = seek_address(PC, ARG2 + ARG3);
        address = return_field(address, (ARG2 + ARG3) % 5);
    }
    else if (ACB - 4 == 156) //DIR IND
    {
        result = return_field(seek_address(PC, ARG3), ARG3);
        address = seek_address(PC, (ARG2 + result) % IDX_MOD);
        address = return_field(address, (ARG2 + result) % IDX_MOD);
    }
    else if (ACB - 4 == 184)  //IND REG
    {
        result = return_field(seek_address(PC, ARG2), ARG2);
        address = seek_address(PC, (result + REG[ARG3]) % IDX_MOD);
        address = return_field(address, (result + REG[ARG3]) % IDX_MOD);
    }
    else if (ACB - 4 == 180) //IND DIR
    {
        result = return_field(seek_address(PC, ARG2), ARG2);
        address = seek_address(PC, (result + ARG3) % IDX_MOD);
        address = return_field(address, (result + ARG3) % IDX_MOD);
    }
    else if (ACB - 4 == 188) //IND IND
    {
        result = return_field(seek_address(PC, ARG2), ARG2) 
            + return_field(seek_address(PC, ARG3), ARG3);
        address = seek_address(PC, result % IDX_MOD);
        address = return_field(address, result % IDX_MOD);
    }
}	

void		cfork(t_process *process)
{
    //PLACE new process at PC place ARG2 % IDX_MOD
	(void)process;

}	

void		lld(t_process *process)
{
// LD without IDX_MOD. Modifies Carry
	(void)process;
}	

void		lldi(t_process *process)
{
// Same as LDI but no IDX_MOD. Modifies Carry
	(void)process;
}	

void		lfork(t_process *process)
{
	(void)process;
// Fork without Modulo
}	
