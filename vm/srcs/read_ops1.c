#include <vm.h>


#include <math.h> // DEBUG MUTHFUCKA!

int			read_live(t_address *current, unsigned char *buff, long int index)
{
	int		temp;
	int		counter;

	counter = 0;
	temp = 0;
	current->operation = buff[index];
	index++;
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

int			read_ld(t_address *current, unsigned char *buff, long int index)
{
	int		temp;
	int		counter;

	counter = -1;
	temp = 0;
	current->operation = buff[index];
	index++;
	if ((buff[index] & 160) == 160)
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
	else if ((buff[index] & 224) == 224)
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
	else if ((buff[index] & 96) == 96)
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
