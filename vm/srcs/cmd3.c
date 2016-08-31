#include <vm.h>

void		sti(t_process *process)
{
    if (ACB - 4 == 168) //REG REG
		edit_field(PC, (REG[ARG2] + REG[ARG3]) % IDX_MOD, REG[ARG1]);
    else if (ACB - 4 == 164) //REG DIR
		edit_field(PC, (REG[ARG2] + ARG3) % IDX_MOD, REG[ARG1]);
    else if (ACB - 4 == 172) //REG IND
		edit_field(PC, 
				(REG[ARG2] + return_field(PC, ARG3)) % IDX_MOD, REG[ARG1]);
    else if (ACB - 4 == 152) //DIR REG
		edit_field(PC, (ARG2 + REG[ARG3]) % IDX_MOD, REG[ARG1]);
    else if (ACB - 4 == 148) //DIR DIR
		edit_field(PC, (ARG2 + ARG3) % IDX_MOD, REG[ARG1]);
    else if (ACB - 4 == 156) //DIR IND
		edit_field(PC, 
				(ARG2 + return_field(PC, ARG3)) % IDX_MOD, REG[ARG1]);
    else if (ACB - 4 == 184)  //IND REG
		edit_field(PC, 
				(return_field(PC, ARG2) + REG[ARG3]) % IDX_MOD, REG[ARG1]);
    else if (ACB - 4 == 180) //IND DIR
		edit_field(PC, (return_field(PC, ARG2) + ARG3) % IDX_MOD, REG[ARG1]);
    else if (ACB - 4 == 188) //IND IND
		edit_field(PC, 
				(return_field(PC, ARG2) + return_field(PC, ARG3))
			   	% IDX_MOD, REG[ARG1]);
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
