#include <vm.h>

long int	ft_pow(int base, int power)
{
	long int	pow;
	int	index;
	index = -1;
	pow = base;
	while (++index <= power)
		pow *= pow;
	return (pow);
}
