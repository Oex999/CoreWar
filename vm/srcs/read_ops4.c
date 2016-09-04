#include <vm.h>

int			read_aff(t_address *current, unsigned char *buff, long int i)
{
    current->operation = buff[i];
    current->arg1 = buff[i + 1];
    return (i);
}
