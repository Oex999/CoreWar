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

int			read_xor(t_address *current, unsigned char *buff, long int index)
{
    int		temp;
    int		counter;
}

 opcode 09............

int			read_zjmp(t_address *current, unsigned char *buff, long int index)
{
    int		temp;
    int		counter;
}
 

 opcode 10............

int			read_ldi(t_address *current, unsigned char *buff, long int index)
{
    int		temp;
    int		counter;
    
    counter = -1;
    temp = 0;
    current->operation = buff[index];
    index++;
    if ((buff[index] & 94) == 94)
    while (++counter <= 1)
    {
        printf("buff in read_ldi = %i\n", buff[index]);
        printf("temp = %i\n", temp);
        temp += buff[index] * (pow(16, 4 - counter));		//pow used for testing
        index++;
        counter++;
        printf("Index = %li\n", index);
        printf("counter = %i\n", counter);
    }
    current->arg1 = temp;
    return (index);
}
*/