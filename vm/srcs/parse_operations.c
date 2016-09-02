#include <vm.h>

int			read_operation1(t_address *current, unsigned char *buff, long int index)
{
    //unsigned int acb;
    //acb = buff[index + 1];
    //printf("acb in read_ops1 = %x...\n", acb);
	//printf("current at address %i, buff indexed at %i with index %li\n", current->address, buff[index], index);
	if (buff[index] == 01)
		index += read_live(current, buff, index);
	if (buff[index] == 02)
		index += read_ld(current, buff, index);
/*	if (buff[index] == 03)
		index += read_st(current, buff, index);
	if (buff[index] == 04)
		index += read_add(current, buff, index);
	if (buff[index] == 05)
		index += read_sub(current, buff, index);
	if (buff[index] == 06)
		index += read_and(current, buff, index);
	if (buff[index] == 07)
		index += read_or(current, buff, index);*/
	return (index);
}



int			read_operation2(t_address *current, unsigned char *buff, long int index)
{
	//printf("current at address %i, buff indexed at %i with index %li\n", current->address, buff[index], index);
    //unsigned int acb;
    //acb = buff[index + 1];
    //printf("acb in read_ops2 = %x...\n", acb);
	//if (buff[index] == 08)
	//	index += read_xor(current, buff, index);
	//if (buff[index] == 09)
	//	index += read_zjmp(current, buff, index);
	//if (buff[index] == 0a) //10
	//	index += read_ldi(current, buff, index);
	if (buff[index] == 0x0b) //11
		index += read_sti(current, buff, index);
	//if (buff[index] == 0c) //12
	//	index += read_fork(current, buff, index);
	//if (buff[index] == 0d) //13
	//	index += read_lld(current, buff, index);
	//if (buff[index] == 0e) //14
	//	index += read_lldi(current, buff, index);
	//if (buff[index] == 0f) //15
	//	index += read_lfork(current, buff, index);
	//if (buff[index] == 10) //16
	//	index += read_aff(current, buff, index);
	return (index);
}


