#include <vm.h>


#include <math.h> // DEBUG MUTHFUCKA!

/* opcode 01............*/

int			read_live(t_address *current, unsigned char *buff, long int index)
{
	int		temp;
	int		counter;

	counter = 0;
	temp = 0;
	current->operation = buff[index];
    printf("Operation found in read_live = %x...\n", current->operation);
	index++;
    printf("after index++, buff[index] now = %x...\n", buff[index]);
	while (counter <= 1)
	{
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

/* opcode 02............*/
/*
int			read_ld(t_address *current, unsigned char *buff, long int index)
{
    int		temp;
    int		counter;
    
    counter = -1;
    temp = 0;
    current->operation = buff[index];
    index++;
    if ((buff[index] & 90) == 90)
        ld_reg(buff, index);
    else if ((buff[index] & 144) == 144)
        ld_dir();
    else if ((buff[index] & 208) == 208)
        ld_ind();
}
 */

int			read_ld(t_address *current, unsigned char *buff, long int index)
{
	int		temp;
	int		counter;

	counter = -1;
	temp = 0;
	current->operation = buff[index];
	index++;
	if ((buff[index] & 0x90) == 0x90)
	{
		while (++counter <= 1) 
		{
			printf("buff = %i\n", buff[index]);
			printf("temp = %i\n", temp);
			temp += buff[index] * (pow(16, 4 - counter));		//pow used for testing
			index++;
			printf("Index = %li\n", index);
			printf("counter = %i\n", counter);
		}

	}
	else if ((buff[index] & 208) == 208)
	{
		while (++counter <= IND_SIZE)
		{
			printf("buff = %i\n", buff[index]);
			printf("temp = %i\n", temp);
			temp += buff[index] * (pow(16, 4 - counter));		//pow used for testing
			index++;
			printf("Index = %li\n", index);
			printf("counter = %i\n", counter);
		}

	}
	else if ((buff[index] & 80) == 80)
	{
		while (++counter <= DIR_SIZE)
		{
			printf("buff = %i\n", buff[index]);
			printf("temp = %i\n", temp);
			temp += buff[index] * (pow(16, 4 - counter));		//pow used for testing
			index++;
			printf("Index = %li\n", index);
			printf("counter = %i\n", counter);
		}

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

/*

int			read_st(t_address *current, unsigned char *buff, long int index)
{
    int		temp;
    int		counter;
}

 opcode 04.

int			read_add(t_address *current, unsigned char *buff, long int index)
{
    int		temp;
    int		counter;
}

 opcode 05............

int			read_sub(t_address *current, unsigned char *buff, long int index)
{
    int		temp;
    int		counter;
}
 */
