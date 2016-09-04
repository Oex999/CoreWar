#include <vm.h>

int			read_live(t_address *current, unsigned char *buff, long int i)
{
    current->operation = buff[i];
    current->arg1 = buff[i + 1] + buff[i + 2] + buff[i + 3] + buff[i + 4];
    i += 4;
	return (i);
}

int			read_ld(t_address *current, unsigned char *buff, long int i)
{
    if (buff[i] == 0x02 && buff[i + 1] == 0x90)
    {
        current->operation = buff[i];
        current->acb = buff[i + 1];
        current->arg1 = buff[i + 2] + buff[i + 3] + buff[i + 4] + buff[i + 5];
        current->arg2 = buff[i + 6];
        i += 6;
    }
    else if (buff[i] == 0x02 && buff[i + 1] == 0x90)
    {
        current->operation = buff[i];
        current->acb = buff[i + 1];

    }
    else if (buff[i] == 0x02 && buff[i + 1] == 0x90)
    {
        current->operation = buff[i];
        current->acb = buff[i + 1];

    }
    return (i);
}

int			read_st(t_address *current, unsigned char *buff, long int i)
{
    current->operation = buff[i];
    current->acb = buff[i + 1];
    current->arg1 = buff[i + 2];
    current->arg2 = buff[i + 3] + buff[i + 4];
    i += 4;
    return (i);
}

int			read_add(t_address *current, unsigned char *buff, long int i)
{
    current->operation = buff[i];
    current->acb = buff[i + 1];
    current->arg1 = buff[i + 2];
    current->arg2 = buff[i + 3];
    current->arg3 = buff[i + 4];
    i += 5;
    return (i);
}

int			read_sub(t_address *current, unsigned char *buff, long int i)
{
    current->operation = buff[i];
    current->acb = buff[i + 1];
    current->arg1 = buff[i + 2];
    current->arg2 = buff[i + 3];
    current->arg3 = buff[i + 4];
    i += 5;
    return (i);
}

