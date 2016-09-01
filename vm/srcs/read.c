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

void             parse_champ_data(t_state *state, char *argv, int champ_no)
{
    int             fd;
	long int		size;
	unsigned char	buff[4000];

	printf("Parsing Champ Data\n");	
    size = -1;
	if ((fd = open(argv, O_RDONLY)) == -1)
        error_exit(state, "Error: Could not open file\n");
	while (++size <= 4000)
		buff[size] = '\0';
    size = -1;
	while (read(fd, &buff[++size], 1) == 1);
	size = -1;
	while (++size <= 3000)
	{
	   if (size % 16 == 0)
		   printf("\n");
	   printf("%.3i ", buff[size]);
	}
	(void)champ_no;
	printf("\nMagic Number = %s", ft_itoabase(buff[1], 16));
	printf("%s", ft_itoabase(buff[2], 16));
	printf("%s\n", ft_itoabase(buff[3], 16));
	printf("Magic Number = %s\n", ft_itoabase(COREWAR_EXEC_MAGIC, 16));
	check_magic(state, buff);
}

void			check_magic(t_state *state, unsigned char *buff)
{
	char		*str;
	char		*magic;
	
	str = ft_strnew(6);
	ft_strcat(str, ft_itoabase(buff[1], 16));
	ft_strcat(str, ft_itoabase(buff[2], 16));
	ft_strcat(str, ft_itoabase(buff[3], 16));
	if (ft_strcmp(str, magic = ft_itoabase(COREWAR_EXEC_MAGIC, 16)) != 0)
		error_exit(state, "Error: Champion Header Incorrect\n");
	free(str);
	free(magic);

}
