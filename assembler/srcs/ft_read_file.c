/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 08:27:09 by oexall            #+#    #+#             */
/*   Updated: 2016/08/13 11:10:25 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

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

int			ft_read_lines(int fd, t_input **input)
{
	char	*line;
	char	**split;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (ft_is_cmd(ft_trimsp(line)))
			ft_input_push_back(input, ft_trimsp(line), 
					ft_get_alias(ft_trimsp(line)));
		else
		{
			split = ft_mysplit(line, ft_oneof(' ', 
						ft_trimsp(line)) ? " \t" : "\t");
			if (split[0])
				ft_input_push_back(input, ft_trimsp(split[0]), 
						ft_get_alias(ft_trimsp(split[0])));
			if (split[0] && split[1])
				ft_input_push_back(input, ft_trimsp(split[1]), 
						ft_get_alias(ft_trimsp(split[1])));
			ft_deltab(split);
		}
		free(line);
	}
	return (1);
}

int			ft_read_file(char *file, t_input **input)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (ft_err("Failed to open file."));
	ft_putendl("DEBUG: Reading"); //DEBUG
	if (!ft_read_lines(fd, input))
		return (ft_err("Failed to read file"));
	ft_putendl("DEBUG: End Reading"); //DEBUG
	if (close(fd) < 0)
		return (ft_err("Failed to close file."));
	return (1);
}
