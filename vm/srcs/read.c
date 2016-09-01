#include <vm.h>

t_u16               read_u16(t_u16 *r)
{
    unsigned char   *data;
    
    data = (unsigned char*)r;
    *r = ((data[1] << 0) | (data[0] << 8));
    return (*r);
}

t_u32               read_u32(t_u32 *r)
{
    unsigned char   *data;
    
    data = (unsigned char*)r;
    *r = ((data[3] << 0 | data[2] << 8 | data[1] << 16 | data[0] << 24));
    return (*r);
}

t_state             parse_champ_data(t_state *state, char *argv, int champ_no)
{
    int             fd;
//    unsigned int    size;
//	char			temp;
//	char			temp2;
//	void			*ptr;
	unsigned char	buff[50];
   
	(void)champ_no;
    //state = malloc(sizeof(*t_state));
    if ((fd = open(argv, O_RDONLY)) == -1)
        error_exit(state, "Error: Could not open file\n");
	printf("magic number %i\n", COREWAR_EXEC_MAGIC);
	read(fd, &buff[0], 1);
//	ptr = &temp;
	printf("0 = %i\n", buff[0]);
//	ft_reverse_bytes(ptr, 2);
//	printf("reverse temp = %i\n", temp);
	read(fd, &buff[1], 1);
//	ptr = &temp2;
	printf("1 = %i\n", buff[1] >> 4);
	printf("1 = %i\n", buff[1] & 16);
	read(fd, &buff[2], 1);
	printf("2 = %i\n", buff[2]);
	read(fd, &buff[3], 1);
	printf("3 = %i\n", buff[3]);
	read(fd, &buff[4], 1);
	printf("magic number %i\n", buff[0] + (buff[1] * 16) + (buff[2] * 16 * 16) + (buff[3] *16 * 16 * 16));
	printf("4 = %i\n", buff[4]);
	read(fd, &buff[5], 1);
	printf("5 = %i\n", buff[5]);
	read(fd, &buff[6], 1);
	printf("6 = %i\n", buff[6]);
	read(fd, &buff[7], 1);
	printf("7 = %i\n", buff[7]);
	read(fd, &buff[8], 1);
	printf("8 = %i\n", buff[8]);
	read(fd, &buff[9], 1);
	printf("9 = %i\n", buff[9]);
	read(fd, &buff[10], 1);
	printf("10 = %i\n", buff[10]);
//	ift_reverse_bytes(ptr, 2);
//	printf("reverse temp2 = %i\n", temp2);
//	buff[0] = (temp * 16) + temp2;
//	printf("buff[0] = %i\n", buff[0]);
    //if (read(fd, &state->champ[champ_no - 1]->header, sizeof(header_t)) != sizeof(header_t))
      //  error_exit(state, "Error: Not a valid header\n");
    
    //read_u32(&state->champ[champ_no - 1]->header.magic);//testing
   // printf("header.magic after read_u32 = %u\n", state->champ[champ_no - 1]->header.magic);//debug
    
//    read_u32(&state->champ[champ_no - 1]->header.prog_size);//testing
    
//    size = state->champ[champ_no - 1]->header.prog_size;
//    printf("header.magic after read_u32 = %u\n", state->champ[champ_no - 1]->header.prog_size);//debug
    
//    if (state->champ[champ_no - 1]->header.magic != COREWAR_EXEC_MAGIC || size > CHAMP_MAX_SIZE)
//        error_exit(state, "Error: Not a valid header\n");
    return (*state);
}
