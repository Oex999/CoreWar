#include <vm.h>

void             parse_champ_data(t_state *state, char *argv, int champ_no)
{
	int             fd;
	unsigned char	buff[4000];

	printf("Parsing Champ Data\n");	
	if ((fd = open(argv, O_RDONLY)) == -1)
		error_exit(state, "Error: Could not open file\n");
	buffer_champion(buff, fd);
	check_magic(state, buff);
	printf("Champ PC points to address %i\n", (MEM_SIZE * 5) / state->champ_count * champ_no - 1);	
	state->champ[champ_no - 1]->pc = seek_address(state, state->begin, 
			(MEM_SIZE * 5) / state->champ_count * champ_no - 1);
	ft_strcpy(state->champ[champ_no - 1]->champ_name, (char *)&buff[4]);
	ft_strcpy(state->champ[champ_no - 1]->champ_comment, 
			(char *)&buff[4 + PROG_NAME_LENGTH + 1]); //Doesn't Work
	deploy_champion(state->champ[champ_no - 1]->pc, buff);
}

void			deploy_champion(t_address *pc, unsigned char *buff)
{
	long int	index;

	(void)pc;
	(void)buff;
	index = 0;
	
}

void            buffer_champion(unsigned char *buff, int fd)
{
	long int	size;
//	int			temp;
    
//	size = -1;
//    while (++size <= 4000)
//		buff[size] = '\0';
	size = -1;
	while (read(fd, &buff[++size], 1) == 1);
	size = -1;
	while (++size <= 3000)
	{
		if (size % 16 == 0)
			printf("\n");
		printf("%3s ", ft_itoabase(buff[size], 16));
	}
}

void			check_magic(t_state *state, unsigned char *buff)
{
	char		*str;
	char		*magic;

	str = ft_strnew(6);
	ft_strcat(str, ft_itoabase(buff[1], 16));
	ft_strcat(str, ft_itoabase(buff[2], 16));
	ft_strcat(str, ft_itoabase(buff[3], 16));
	printf("file magic = %s\n", str);
	if (ft_strcmp(str, magic = ft_itoabase(COREWAR_EXEC_MAGIC, 16)) != 0)
		error_exit(state, "Error: Champion Header Incorrect\n");
	free(str);
	free(magic);
}
