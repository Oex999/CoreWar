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

t_state             parse_champ_data(t_state *state, char *argv, int i)
{
    int             fd;
    unsigned int    size;
    
    //state = malloc(sizeof(*t_state));
    if ((fd = open(argv, O_RDONLY)) != 1)
        error_exit(state, "Error: Could not open file\n");
    if (read(fd, &state->champ[i]->header, sizeof(header_t)) != sizeof(header_t))
        error_exit(state, "Error: Not a valid header\n");
    //testing
    read_u32(&state->champ[i]->header.magic);
    //testing
    read_u32(&state->champ[i]->header.prog_size);
    size = state->champ[i]->header.prog_size;
    
    if (state->champ[i]->header.magic != COREWAR_EXEC_MAGIC || size > CHAMP_MAX_SIZE)
        error_exit(state, "Error: Not a valid header\n");
    return (*state);
}