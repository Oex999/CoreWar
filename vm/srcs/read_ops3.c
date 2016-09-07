#include <vm.h>

int			read_sti(t_address *current, unsigned char *buff, long int i)
{
    if (buff[i + 1] == 0x64)
    {
        current->operation = buff[i];
        printf("OPCODE = %x\n", current->operation);
        current->acb = buff[i + 1];
        printf("ACB = %x\n", current->acb);
        current->arg1 = buff[i + 2];
        current->arg2 = buff[i + 3] + buff[i + 4];
        current->arg3 = buff[i + 5];
        i += 5;
        printf("i at buff[i] after sti = %x...\n", buff[i]);
        printf("index at sti = %li...\n", i);
    }

    else if (buff[i + 1] == 0x68)
    {
        current->operation = buff[i];
        printf("OPCODE = %x\n", current->operation);
        current->acb = buff[i + 1];
        printf("ACB = %x\n", current->acb);
        current->arg1 = buff[i + 2];
        current->arg2 = buff[i + 3] + buff[i + 4];
        current->arg3 = buff[i + 5] + buff[i + 6];
        i += 5;
        i++;
    }
    return (i);
}

int			read_fork(t_address *current, unsigned char *buff, long int i)
{
    current->operation = buff[i];
    printf("OPCODE = %x\n", current->operation);
    current->arg1 = buff[i + 1] + buff[i + 2];
    i += 2;

    return (i);
}

int			read_lld(t_address *current, unsigned char *buff, long int i)
{
    current->operation = buff[i];
    printf("OPCODE = %x\n", current->operation);
    current->arg1 = buff[i + 1] + buff[i + 2];
    i += 2;
    return (i);
}

int			read_lldi(t_address *current, unsigned char *buff, long int i)//fix
{
    current->operation = buff[i];
    printf("OPCODE = %x\n", current->operation);
    current->arg1 = buff[i + 1] + buff[i + 2];
    i += 2;
    return (i);
}

int			read_lfork(t_address *current, unsigned char *buff, long int i) //fix
{
    if (buff[i + 1] == 0x09)
        i++;
    else
    {
        current->operation = buff[i];
        printf("OPCODE = %x\n", current->operation);
        current->arg1 = buff[i + 1] + buff[i + 2];
        i += 2;
    }
    return (i);
}
