#include <vm.h>

int			read_and(t_address *current, unsigned char *buff, long int i)
{
    current->operation = buff[i];
    printf("OPCODE = %x\n", current->operation);
    current->acb = buff[i + 1];
    printf("ACB = %x\n", current->acb);
    current->arg1 = buff[i + 2];
    current->arg2 = buff[i + 3];
    current->arg3 = buff[i + 4];
    i += 3;
    return (i);

}
 
int			read_or(t_address *current, unsigned char *buff, long int i)
{
    current->operation = buff[i];
    printf("OPCODE = %x\n", current->operation);
    current->acb = buff[i + 1];
    printf("ACB = %x\n", current->acb);
    current->arg1 = buff[i + 2];
    current->arg2 = buff[i + 3];
    current->arg3 = buff[i + 4];
    i += 3;
    return (i);
}

int			read_xor(t_address *current, unsigned char *buff, long int i)
{
    current->operation = buff[i];
    printf("OPCODE = %x\n", current->operation);
    current->acb = buff[i + 1];
    printf("ACB = %x\n", current->acb);
    current->arg1 = buff[i + 2];
    current->arg2 = buff[i + 3];
    current->arg3 = buff[i + 4];
    i += 4;
    return (i);
}

int			read_zjmp(t_address *current, unsigned char *buff, long int i)
{
    current->operation = buff[i];
    printf("OPCODE = %x\n", current->operation);
    current->arg1 = buff[i + 1];
    current->arg2 = buff[i + 2];
    i += 2;
    return (i);
}

int			read_ldi(t_address *current, unsigned char *buff, long int i)
{
    current->operation = buff[i];
    printf("OPCODE = %x\n", current->operation);
    current->acb = buff[i + 1];
    printf("ACB = %x\n", current->acb);
    current->arg1 = buff[i + 2] + buff[i + 3];
    current->arg2 = buff[i + 4] + buff[i + 5];
    current->arg3 = buff[i + 6];
    i += 6;
    return (i);
}
