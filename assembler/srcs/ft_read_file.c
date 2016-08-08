/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 08:27:09 by oexall            #+#    #+#             */
/*   Updated: 2016/08/08 10:14:15 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		ft_get_alias(char *str)
{
	if (ft_strncmp(str, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
		return (NAME);
	if (ft_strncmp(str, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) == 0)
		return (COMMENT);
	return (-1);
}

int		ft_read_file(char *file, t_input *input)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (ft_err("Failed to open file."));
	line = NULL;
	while (get_next_line(fd, &line))
	{
		ft_input_push_back(&input, line, ft_get_alias(line));
		ft_putendl(line);
		free(line);
	}
	if (close(fd) < 0)
		return (ft_err("Failed tot close file."));
	return (1);
}
