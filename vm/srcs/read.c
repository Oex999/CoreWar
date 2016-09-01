#include <vm.h>

void             parse_champ_data(t_state *state, char *argv, int champ_no)
{
	int             fd;
	unsigned char	buff[4000];

	printf("Parsing Champ Data\n");	
	size = -1;
	if ((fd = open(argv, O_RDONLY)) == -1)
		error_exit(state, "Error: Could not open file\n");
	(void)champ_no;
	check_magic(state, buff);
	state->champions[champ_no - 1]->pc = seek_address(state->begin, 
			(MEM_SIZE * 5) / state->champ_count * champ_no - 1);
	ft_strcpy(state->champions[champ_no - 1]->champ_name, buff[4], CHAMP_NAME_SIZE);
	ft_strcpy(state->champions[champ_no - 1]->champ_comment, 
			buff[4 + CHAMP_NAME_SIZE], CHAMP_COMMENT_SIZE);
	deploy_champion(state->champions[champ_no - 1]->pc, buff);
}

void			deploy_champion(t_address *pc, unsigned char *buff)
{
	long int	index;

	index = 0;

}

void            buffer_champion(unsigned char *buff, int fd)
{
	long int	size;
    
	size = -1;
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
