#include <vm.h>

void            ft_reverse_bytes(void *mem, size_t size)
{
    int     j;
    int     i;
    char    *tmp;
    char    *ptr;

    i = size - 1;
    j = 0;
    ptr = (char *)mem;
    tmp = malloc(size);
    ft_memcpy(tmp, mem, size);
    while (i >= 0)
    {
        ptr[j] = tmp[i];
        j++;
        i--;
    }
    free(tmp);
}
