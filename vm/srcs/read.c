#include <vm.h>

void             parse_champ_data(t_state *state, char *argv, int champ_no)
{
	int             fd;
	char			buff[4000];

	printf("Parsing Champ Data\n");	
	if ((fd = open(argv, O_RDONLY)) == -1)
		error_exit(state, "Error: Could not open file\n");
	check_magic(state, buff);
	state->champ[champ_no - 1]->pc = seek_address(state, state->begin, 
			(MEM_SIZE * 5) / state->champ_count * champ_no - 1);
	ft_strncpy(state->champ[champ_no - 1]->champ_name, &buff[4], PROG_NAME_LENGTH);
	ft_strncpy(state->champ[champ_no - 1]->champ_comment, 
			&buff[4 + PROG_NAME_LENGTH], COMMENT_LENGTH);
	deploy_champion(state->champ[champ_no - 1]->pc, buff);
}

void			deploy_champion(t_address *pc, char *buff)
{
	long int	index;

	(void)pc;
	(void)buff;
	index = 0;
	
}

void            buffer_champion(char *buff, int fd)
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

void			check_magic(t_state *state, char *buff)
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
