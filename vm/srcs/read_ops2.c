#include <vm.h>
#include <math.h> // DEBUG MUTHFUCKA!
/* opcode 06............

int			read_and(t_address *current, unsigned char *buff, long int index)
{
    int		temp;
    int		counter;
}

 opcode 07............
 
int			read_or(t_address *current, unsigned char *buff, long int index)
{
    int		temp;
    int		counter;
}

 opcode 08............
*/

int			read_xor(t_address *current, unsigned char *buff, long int i)
{
    current->operation = buff[i];
    current->acb = buff[i + 1];
    current->arg1 = buff[i + 2];
    current->arg2 = buff[i + 3] + buff[i + 4];
    current->arg3 = buff[i + 5];
    i += 7;
    return (i);
}

int			read_zjmp(t_address *current, unsigned char *buff, long int i)
{
    current->operation = buff[i];
    current->arg1 = buff[i + 1];
    current->arg2 = buff[i + 2];
    i += 2;
    return (i);
}

int			read_ldi(t_address *current, unsigned char *buff, long int i)
{
    current->operation = buff[i];
    current->acb = buff[i + 1];
    current->arg1 = buff[i + 2] + buff[i + 3];
    current->arg2 = buff[i + 4] + buff[i + 5];
    current->arg3 = buff[i + 6];
    i += 6;
    return (i);
}
