#include <vm.h>

int			read_operation1(t_address *current, unsigned char *buff, long int i)
{
	if (buff[i] == 0x01)
    {
        printf("found live...");
        i += read_live(current, buff, i);
        return (i);
    }
	else if (buff[i] == 0x02)
    {
		printf("found ld...");
        i += read_ld(current, buff, i);
        return (i);
    }
    else if (buff[i] == 0x03 && buff[i + 1] == 0x70)
    {
        printf("found st...");
        i += read_st(current, buff, i);
        printf("\ncurrent @ index in st = %x...\n", buff[i]);
        return (i);
    }
	else if (buff[i] == 0x04 && buff[i + 1] == 0x54)
    {
		printf("found add...");
        i += read_add(current, buff, i);
        return (i);
    }
    else if (buff[i] == 0x05 && buff[i + 1] == 0x54)
    {
        printf("found sub...");
        i += read_add(current, buff, i);
        return (i);
    }
    else if (buff[i] == 0x06 && buff[i + 1] == 0x54)
    {
        printf("found and...");
        i += read_add(current, buff, i);
        return (i);
    }
    else if (buff[i] == 0x07 && buff[i + 1] == 0x54)
    {
        printf("found or..");
        i += read_add(current, buff, i);
        return (i);
    }
    printf("index = %li after read_op1\n", i);
	return (i);
}

int			read_operation2(t_address *current, unsigned char *buff, long int i)
{
    if (buff[i] == 0x08 && buff[i + 1] == 0x64)
    {
        printf("found xor...");
        i += read_sti(current, buff, i);
        return (i);
    }
    else if (buff[i] == 0x09)
    {
        printf("found zjmp...");
        i += read_zjmp(current, buff, i);
        return (i);
    }
    else if (buff[i] == 0x0a && buff[i + 1] == 0x94)
    {
        printf("found ldi...");
        i += 6;
        return (i);
    }
    else if (buff[i] == 0x0b)
    {
        printf("found sti...");
        i += read_sti(current, buff, i);
        return (i);
    }
    else if (buff[i] == 0x0c)
    {
        printf("found fork...");
        i += read_fork(current, buff, i);
        return (i);
    }
    else if (buff[i] == 0x0d)
    {
        printf("found lld...");
        i += read_lld(current, buff, i);
        return (i);
    }
    else if (buff[i] == 0x0e)
    {
        printf("found lld...");
        i += read_lld(current, buff, i);
        return (i);
    }
    else if (buff[i] == 0x0f)
    {
        printf("found lld...");
        i += read_lld(current, buff, i);
        return (i);
    }
    else if (buff[i] == 0x10)
    {
        printf("found aff...");
        i += read_aff(current, buff, i);
        return (i);
    }
    printf("index = %li after read_op2\n", i);
	return (i);
}