#include <vm.h>

int			read_operation1(t_address *current, unsigned char *buff, long int index)
{
    printf("This is the start of read_operation1...\n");
    //t_process *process = NULL;
    //t_state *state = NULL;
    //unsigned int acb;
    //acb = buff[index + 1];
    //printf("acb in read_ops1 = %x...\n", acb);
	//printf("current at address %i, buff indexed at %x = with index %li\n", current->address, buff[index], index);
	if (buff[index] == 0x01)
    {
        index += 4;
        printf("LIVE FOUND:...\n");
		//index += read_live(current, buff, index);
    }
    
	if (buff[index] == 0x02 && buff[index + 1] == 0x90)
    {
        printf("LD FOUND:...\n");
		//index += read_ld(current, buff, index);
        current->operation = buff[index];
        printf("current op in ST = %i...\n", current->operation);
        current->arg1 = buff[index + 2] + buff[index + 3] + buff[index + 4] + buff[index + 5];
        current->arg2 = buff[index + 6];
        printf("arg1 in LD = %i...\n", current->arg1);
        printf("arg2 in LD = %x...\n", current->arg2);
        index += 6;
        
    }

    if (buff[index] == 0x03 && buff[index + 1] == 0x70)
    {
        printf("ST FOUND:...\n");
        current->operation = buff[index];
        printf("current op in ST = %i...\n", current->operation);
        current->arg1 = buff[index + 2];
        current->arg2 = buff[index + 3] + buff[index + 4];
        printf("arg1 in ST = %x...\n", current->arg1);
        printf("arg2 in ST = %x...\n", current->arg2);
        index += 4;
        
        //index += read_st(current, buff, index);
    }
    
	if (buff[index] == 0x04 && buff[index + 1] == 0x54)
    {
        index += 5;
        printf("ADD FOUND:...\n");
        current->operation = buff[index];
        printf("current op in ST = %i...\n", current->operation);
        current->arg1 = buff[index + 2];
        current->arg2 = buff[index + 3];
        current->arg3 = buff[index + 4];
        printf("arg1 in ADD = %x...\n", current->arg1);
        printf("arg2 in ADD = %x...\n", current->arg2);
        printf("arg3 in ADD = %x...\n", current->arg3);
		//index += read_add(current, buff, index);
    }
//	if (buff[index] == 05)
//		index += read_sub(current, buff, index);
    
    if (buff[index] == 0x05 && buff[index + 1] == 0x54)
    {
        index += 5;
        printf("SUB FOUND:...\n");
        //index += read_add(current, buff, index);
    }
//	if (buff[index] == 06)
//		index += read_and(current, buff, index);
//	if (buff[index] == 07)
//		index += read_or(current, buff, index);*/
	return (index);
}



int			read_operation2(t_address *current, unsigned char *buff, long int index)
{
    printf("This is the start of read_operation2...\n");
    //t_state *state = NULL;
	//printf("current at address %i, buff indexed at %x with index %li\n", current->address, buff[index], index);
    //unsigned int acb;
    //acb = buff[index + 1];
    //printf("acb in read_ops2 = %x...\n", acb);
	//if (buff[index] == 08)
	//	index += read_xor(current, buff, index);
    if (buff[index] == 0x08 && buff[index + 1] == 0x64) //8
    {
        //index += read_sti(current, buff, index);
        index += 7;
        printf("XOR FOUND:...\n");
    }
    
	//if (buff[index] == 09)
	//	index += read_zjmp(current, buff, index);
    if (buff[index] == 0x09) //9
    {
        //index += read_sti(current, buff, index);
        index += 2;
        printf("ZJMP FOUND:...\n");
    }

	//if (buff[index] == 0a) //10
	//	index += read_ldi(current, buff, index);
    
    if (buff[index] == 0x0a && buff[index + 1] == 0x94) //10
    {
        //index += read_ldi(current, buff, index);
        index += 6;
        printf("LDI FOUND:...\n");
    }
    
    
    if (buff[index] == 0x0b) //11
    {
        if (buff[index + 1] == 0x68)
        {
            //index += read_sti(current, buff, index);
            index += 5;
            printf("STI FOUND:...buff[index = %x\n", buff[index]);
        }
        else if (buff[index + 1] == 0x64)
        {
            //index += read_sti(current, buff, index);
            index += 4;
            printf("STI FOUND:...buff[index = %x\n", buff[index]);
        }
    }
    
	//if (buff[index] == 0c) //12
	//	index += read_fork(current, buff, index);
    
    if (buff[index] == 0x0c) //12
    {
        current->operation = buff[index];
        printf("current op in fork = %i...\n", current->operation);
        current->arg1 = buff[index + 1] + buff[index + 2];
        printf("arg1 in fork = %i...\n", current->arg1);
        //index += read_fork(current, buff, index);
        puts("starting Fork parsing");
        //ft_putnbr(sizeof( process->current_op.operation));
        //state->champ[0]->current_op.operation = buff[index];

        //ARG1 = buff[index + 1] + buff[index + 2];
        //cfork(state, process);
        index += 2;
        printf("FORK FOUND:...\n");
    }
    
	//if (buff[index] == 0d) //13
	//	index += read_lld(current, buff, index);
    
    if (buff[index] == 0x0d) //13
    {
        //index += read_lld(current, buff, index);
        index += 2;
        printf("LLD FOUND:...\n");
    }

	//if (buff[index] == 0e) //14
	//	index += read_lldi(current, buff, index);
	//if (buff[index] == 0f) //15
	//	index += read_lfork(current, buff, index);
	//if (buff[index] == 10) //16
	//	index += read_aff(current, buff, index);
    
    if (buff[index] == 0x10) //16
    {
        //index += read_aff(current, buff, index);
        index += 1;
        printf("AFF FOUND:...\n");
    }

	return (index);
}


