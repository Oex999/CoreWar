#include <vm.h>

void		sti(t_process *process)
{
    int         address;
    int         result;
// EDIT ALL ACB NUMBERS for ARG2 & ARG3 creating place that ARG1 is put
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

void		cfork(t_process *process)
{
    //PLACE new process at PC place ARG1 % IDX_MOD
	(void)process;

}	

void		lld(t_process *process)
{
// LD without IDX_MOD. Modifies Carry
	(void)process;
}	

void		lldi(t_process *process)
{
// SAme as LDI but no IDX_MOD. Modifies Carry
	(void)process;
}	

void		lfork(t_process *process)
{
	(void)process;
// Fork without Modulo
}	
