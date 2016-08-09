/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 08:27:09 by oexall            #+#    #+#             */
/*   Updated: 2016/08/09 14:34:50 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void		ft_deltab(char **tab)
{
	int	i;

	if (tab)
	{
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

int			ft_is_cmd(char *str)
{
	int	i;

	i = -1;
	while (++i < 16)
		if (ft_strncmp(str, g_op_tab[i].name, ft_strlen(g_op_tab[i].name)) == 0)
			return (i);
	return (-1);
}

int			ft_get_alias(char *str)
{
	if (ft_strncmp(str, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
		return (NAME);
	else if (ft_strncmp(str, COMMENT_CMD_STRING,
			ft_strlen(COMMENT_CMD_STRING)) == 0)
		return (COMMENT);
	else if (str[ft_strlen(str) - 1] == LABEL_CHAR
			&& str[ft_strlen(str)] == '\0')
		return (LABEL);
	else if (ft_is_cmd(str) > -1)
		return (CMD);
	return (UNKNOWN);
}

int			ft_read_file(char *file, t_input **input)
{
	int		fd;
	char	*line;
	char	**split;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (ft_err("Failed to open file."));
	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (ft_strlen(line) > 0 && line[0] != COMMENT_CHAR)
		{
			split = ft_strsplit(line, '\t');
			if (split[0])
				ft_input_push_back(input, split[0], ft_get_alias(split[0]));
			if (split[0] && split[1])
				ft_input_push_back(input, split[1], ft_get_alias(split[1]));
			ft_deltab(split);
		}
		free(line);
	}
	if (close(fd) < 0)
		return (ft_err("Failed to close file."));
	return (1);
}
