/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 08:27:09 by oexall            #+#    #+#             */
/*   Updated: 2016/08/12 09:24:48 by oexall           ###   ########.fr       */
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
		if (ft_strlen(line) <= 0 || line[0] == COMMENT_CHAR)
			continue ;
		if (!ft_val_label(ft_trimsp(line), 0) && (ft_is_cmd(ft_trimsp(line)) ||
				ft_strncmp(ft_trimsp(line), "live", 4) == 0))
		{
			ft_input_push_back(input, ft_trimsp(line),
				   	ft_get_alias(line));
			continue ;
		}
		split = ft_mysplit(line, (ft_is_cmd(line) ? "" : " \t"));
		ft_format(&split);
		if (split[0])
			ft_input_push_back(input, split[0], ft_get_alias(split[0]));
		if (split[0] && split[1])
			ft_input_push_back(input, split[1], ft_get_alias(split[1]));
		ft_deltab(split);
		free(line);
	}
	return (1);
}

int			ft_read_file(char *file, t_input **input)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (ft_err("Failed to open file."));
	if (!ft_read_lines(fd, input))
		return (ft_err("Failed to read file"));
	if (close(fd) < 0)
		return (ft_err("Failed to close file."));
	return (1);
}
