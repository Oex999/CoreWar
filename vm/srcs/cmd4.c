#include <vm.h>

void	    	aff(t_process *process)
{
	char		c;

	if ((ACB & 128) == 128)
		if (ARG1 / 16 < 16 && ARG1 / 16 > -1)
		{
			c = REG[ARG1] % 256;
			write(1, &c, 1);
		}
}

t_address       *seek_address(t_state *state, t_address *mem, int address)
{
    t_address   *ptr;

    ptr = mem;
	if (ptr->address != address % MEM_SIZE * 5)
	{
    	while (ptr->address != address % MEM_SIZE * 5)
		{
			//printf("Seeking Address %i from %i\n", address % MEM_SIZE * 5, ptr->address);
			ptr = ptr->next;
		}
	}
	else
		error_exit(state, "No address location match...");
    return (ptr);
}

int             return_field(t_state *state, t_address *address, int field)
{
    address = seek_address(state, address, field -= (field % 5));
	field = field % 5;
    if (field == 0)
        return (address->operation);
	else if (field == 1)
        return (address->acb);
	else if (field == 2)
        return (address->arg1);
	else if (field == 3)
        return (address->arg2);
	else if (field == 4)
        return (address->arg3);
	else
		error_exit(state, "Invalid memory location...");
    return (0);
}

void            edit_field(t_state *state, t_address *address, int field, int new_value)
{
    address = seek_address(state, address, field -= (field % 5));
    field = field % 5;
    if (field == 0)
        address->operation = new_value;
	else if (field == 1)
        address->acb = new_value;
	else if (field == 2)
        address->arg1 = new_value;
	else if (field ==3)
        address->arg2 = new_value;
	else if (field == 4)
        address->arg3 = new_value;
	else
		error_exit(state, "Invalid memory location...");
}
