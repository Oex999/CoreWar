#include <vm.h>

void	assign_header(t_state *state, unsigned char *buff, int champ_nbr)
{
	header_t	header;
	t_process	champ;
	int		name_len;
	int		comment_len;
	int		magic_len;

	magic_len = 3;
	name_len = PROG_NAME_LENGTH + magic_len;
	comment_len = COMMENT_LENGTH + name_len;

	while (i <= magic_len)
	{
		*(header->magic) = buff[i];
		(*(header->magic))++;
		i++;
	}
	while (i <= name_len)
	{
		*(header->prog_name) = buff[i];
		(*(header->prog_name))++;
		i++;
	}
	*(header->prog_name) = '\0';
	while (i <= comment_len)
	{
		*(header->comment) = buff[i];
		(*(header->comment))++;
		i++;
	}
	*(header->comment) = '\0';
}
