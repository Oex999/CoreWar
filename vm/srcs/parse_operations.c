#include <vm.h>

int			read_operation1(t_address *current, unsigned char *buff, long int i)
{
	if (buff[i] == 0x01)
        i += read_live(current, buff, i);
    
	if (buff[i] == 0x02)
		i += read_ld(current, buff, i);
    if (buff[i] == 0x03 && buff[i + 1] == 0x70)
        i += read_st(current, buff, i);
	if (buff[i] == 0x04 && buff[i + 1] == 0x54)
		i += read_add(current, buff, i);
    if (buff[i] == 0x05 && buff[i + 1] == 0x54)
           i += read_add(current, buff, i);
	return (i);
}



int			read_operation2(t_address *current, unsigned char *buff, long int i)
{
    if (buff[i] == 0x08 && buff[i + 1] == 0x64)
        i += read_sti(current, buff, i);
    if (buff[i] == 0x09)
        i += read_zjmp(current, buff, i);
    if (buff[i] == 0x0a && buff[i + 1] == 0x94)
        i += 6;
    if (buff[i] == 0x0b)
         i += read_sti(current, buff, i);
    if (buff[i] == 0x0c)
        current->operation = buff[i];
        current->arg1 = buff[i + 1] + buff[i + 2];
        i += 2;
    if (buff[i] == 0x0d)
        i += read_lld(current, buff, i);
    if (buff[i] == 0x10)
        i += read_aff(current, buff, i);
	return (i);
}