#include <vm.h>

int			read_operation1(t_address *current, unsigned char *buff, long int i)
{
	if (buff[i] == 0x01)
        i += read_live(current, buff, i);
    /*
        current->operation = buff[i];
        current->arg1 = buff[i + 1] + buff[i + 2] + buff[i + 3] + buff[i + 4];
        i += 4;
		//index += read_live(current, buff, index);
     */
    
	if (buff[i] == 0x02)
    {
		i += read_ld(current, buff, i);
        /*
        current->operation = buff[i];
        current->acb = buff[i + 1];
        current->arg1 = buff[i + 2] + buff[i + 3] + buff[i + 4] + buff[i + 5];
        current->arg2 = buff[i + 6];
        i += 6;
        */
    }

    if (buff[i] == 0x03 && buff[i + 1] == 0x70)
    {
        /*
        current->operation = buff[i];
        current->acb = buff[i + 1];
        current->arg1 = buff[i + 2];
        current->arg2 = buff[i + 3] + buff[i + 4];
        i += 4;
         */
        i += read_st(current, buff, i);
    }
    
	if (buff[i] == 0x04 && buff[i + 1] == 0x54)
    {
        /*
        current->operation = buff[i];
        current->acb = buff[i + 1];
        current->arg1 = buff[i + 2];
        current->arg2 = buff[i + 3];
        current->arg3 = buff[i + 4];
        i += 5;
         */
		i += read_add(current, buff, i);
    }

    if (buff[i] == 0x05 && buff[i + 1] == 0x54)
    {
        /*
        current->operation = buff[i];
        current->acb = buff[i + 1];
        current->arg1 = buff[i + 2];
        current->arg2 = buff[i + 3];
        current->arg3 = buff[i + 4];
        i += 5;
         */
        i += read_add(current, buff, i);
    }
    
//	if (buff[index] == 06)
//		index += read_and(current, buff, index);
//	if (buff[index] == 07)
//		index += read_or(current, buff, index);*/
	return (i);
}



int			read_operation2(t_address *current, unsigned char *buff, long int i)
{
    if (buff[i] == 0x08 && buff[i + 1] == 0x64) //8
    {
        i += read_sti(current, buff, i);
        /*
        current->operation = buff[i];
        current->acb = buff[i + 1];
        current->arg1 = buff[i + 2];
        current->arg2 = buff[i + 3] + buff[i + 4];
        current->arg3 = buff[i + 5];
        i += 7;
         */
    }

    if (buff[i] == 0x09) //9
    {
        i += read_zjmp(current, buff, i);
        /*
        current->operation = buff[i];
        current->arg1 = buff[i + 1];
        current->arg2 = buff[i + 2];
        i += 2;
         */
    }

    if (buff[i] == 0x0a && buff[i + 1] == 0x94) //10 ///////dododooooooo
    {
        //index += read_ldi(current, buff, index);
        i += 6;
        printf("LDI FOUND:...\n");
    }
    
    
    if (buff[i] == 0x0b) //11
    {
        i += read_sti(current, buff, i);
        /*
        if (buff[i + 1] == 0x68)
        {
            current->operation = buff[i];
            current->acb = buff[i + 1];
            current->arg1 = buff[i + 2];
            current->arg2 = buff[i + 3] + buff[i + 4];
            current->arg3 = buff[i + 5] + buff[i + 6];
            i += 5;
            i++;
        }
        else if (buff[i + 1] == 0x64)
        {
            current->operation = buff[i];
            current->acb = buff[i + 1];
            current->arg1 = buff[i + 2];
            current->arg2 = buff[i + 3] + buff[i + 4];
            current->arg3 = buff[i + 5];
            i += 4;
        }
         */
    }
    
    if (buff[i] == 0x0c) //12
    {
        current->operation = buff[i];
        current->arg1 = buff[i + 1] + buff[i + 2];
        i += 2;
    }

    if (buff[i] == 0x0d) //13
    {
        i += read_lld(current, buff, i);
        /*
        current->operation = buff[i];
        current->arg1 = buff[i + 1] + buff[i + 2];
        i += 2;
        printf("LLD FOUND:...\n");
         */
    }

	//if (buff[index] == 0e) //14
	//	index += read_lldi(current, buff, index);
	//if (buff[index] == 0f) //15
	//	index += read_lfork(current, buff, index);
	//if (buff[index] == 10) //16
	//	index += read_aff(current, buff, index);
    
    if (buff[i] == 0x10) //16
    {
        //index += read_aff(current, buff, index);
        i += 1;
        printf("AFF FOUND:...\n");
    }

	return (i);
}


