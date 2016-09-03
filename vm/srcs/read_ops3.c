#include <vm.h>
#include <math.h> // DEBUG MUTHFUCKA!
/* opcode 11............

int			read_sti(t_address *current, unsigned char *buff, long int index)
{
    int		temp;
    int		counter;
    
    //counter = -1;
    counter = 0;
    temp = 0;
    current->operation = buff[index];
    printf("current->operation in read_sti = %x...\n", current->operation);
    //index++;
    printf("buf[index] in read_sti = %x...\n", buff[index]);
    if ((buff[index] & 0x68) == 0x68)
    {
        while (++counter <= 1)
        {
            printf("buff = %x\n", buff[index]);
            printf("temp = %i\n", temp);
            temp += buff[index] * (pow(16, 4 - counter));		//pow used for testing
            index++;
            printf("Index = %li\n", index);
            printf("counter = %i\n", counter);
        }
         
        while 
        
    }
    index++;
    counter = -1;
    temp = 0;
    while (++counter <= 1)
    {
        printf("buff = %i\n", buff[index]);
        printf("temp = %i\n", temp);
        temp += buff[index] * (pow(16, 4 - counter));		//pow used for testing
        index++;
        printf("Index = %li\n", index);
        printf("counter = %i\n", counter);
    }
         
        
    return (index);
}


 opcode 12............

int			read_fork(t_address *current, unsigned char *buff, long int index)
{
    int		temp;
    int		counter;
}
 

 opcode 13............

int			read_lld(t_address *current, unsigned char *buff, long int index)
{
    int		temp;
    int		counter;
}
 opcode 14............

int			read_lldi(t_address *current, unsigned char *buff, long int index)
{
    int		temp;
    int		counter;
}

 opcode 15............

int			read_lfork(t_address *current, unsigned char *buff, long int index)
{
    int		temp;
    int		counter;
}
 */
