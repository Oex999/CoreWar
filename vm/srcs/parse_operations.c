#include <vm.h>

int			read_operation1(t_address *current, unsigned char *buff, long int index)
{
	printf("current at address %i, buff indexed at %i with index %li\n", current->address, buff[index], index);
	if (buff[index] == 1)
		index += read_live(current, buff, index);
	if (buff[index] == 2)
		index += read_ld(current, buff, index);
/*	if (buff[index] == 3)
		index += read_st(current, buff, index);
	if (buff[index] == 4)
		index += read_add(current, buff, index);
	if (buff[index] == 5)
		index += read_sub(current, buff, index);
	if (buff[index] == 6)
		index += read_and(current, buff, index);
	if (buff[index] == 7)
		index += read_or(current, buff, index);*/
	return (index);
}




int			read_operation2(t_address *current, unsigned char *buff, long int index)
{
	printf("current at address %i, buff indexed at %i with index %li\n", current->address, buff[index], index);


/*	if (buff[index] == 8)
		index += read_xor(current, buff, index);
	if (buff[index] == 9)
		index += read_zjmp(current, buff, index);
	if (buff[index] == 10)
		index += read_ldi(current, buff, index);
	if (buff[index] == 11)
		index += read_sti(current, buff, index);
	if (buff[index] == 12)
		index += read_fork(current, buff, index);
	if (buff[index] == 13)
		index += read_lld(current, buff, index);
	if (buff[index] == 14)
		index += read_lldi(current, buff, index);
	if (buff[index] == 15)
		index += read_lfork(current, buff, index);
	if (buff[index] == 16)
		index += read_aff(current, buff, index);*/
	return (index);
}
