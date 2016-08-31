#include <vm.h>

void	    	aff(t_process *process)
{
	(void)process;
// ARG1 is registry. Character is printed on standard output. Mod 256
}

t_address       *seek_address(t_address *mem, int address)
{
    t_address   *ptr;

    ptr = mem;
    while (ptr->address != address % MEM_SIZE)
        ptr = ptr->next;
    return (ptr);
}

int             return_field(t_address *address, int field)
{
    address = seek_address(address, field);
	field = field % 5;
    if (field == 0)
        return (address->operation);
    if (field == 1)
        return (address->acb);
    if (field == 2)
        return (address->arg1);
    if (field == 3)
        return (address->arg2);
    if (field == 4)
        return (address->arg3);
    return (0);
}

void            edit_field(t_address *address, int field, int new_value)
{
    address = seek_address(address, field);
    field = field % 5;
    if (field == 0)
        address->operation = new_value;
    if (field == 1)
        address->acb = new_value;
    if (field == 2)
        address->arg1 = new_value;
    if (field ==3)
        address->arg2 = new_value;
    if (field == 4)
        address->arg3 = new_value;
}
