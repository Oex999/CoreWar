#include <vm.h>

int			read_aff(t_address *current, unsigned char *buff, long int i)
{
    current->operation = buff[i];
    printf("OPCODE = %x\n", current->operation);
    current->arg1 = buff[i + 1];
    return (i);
}
