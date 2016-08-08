/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 08:27:09 by oexall            #+#    #+#             */
/*   Updated: 2016/08/08 13:51:02 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static void	ft_deltab(char **tab)
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

int			ft_get_alias(char *str)
{
	if (ft_strncmp(str, ".name", 5) == 0)
		return (0);
	if (ft_strncmp(str, ".comment", 8) == 0)
		return (1);
	return (-1);
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
		if (ft_strlen(line) > 0)
		{
			split = ft_strsplit(line, '\t');
			if (split[0] && !split[1])
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
