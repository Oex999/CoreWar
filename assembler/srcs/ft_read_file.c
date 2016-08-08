/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 08:27:09 by oexall            #+#    #+#             */
/*   Updated: 2016/08/08 12:46:59 by oexall           ###   ########.fr       */
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

int			ft_get_alias(char *str, t_input **input)
{
	char	**split;

	if (ft_strncmp(str, ".name", 5) == 0)
		return (0);
	if (ft_strncmp(str, ".comment", 8) == 0)
		return (1);
	split = ft_strsplit(str, '\t');
	(void)input;
	ft_deltab(split);
	return (-1);
}

int			ft_read_file(char *file, t_input **input)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (ft_err("Failed to open file."));
	line = NULL;
	while (get_next_line(fd, &line))
	{
		ft_input_push_back(input, line, ft_get_alias(line, input));
		free(line);
	}
	if (close(fd) < 0)
		return (ft_err("Failed to close file."));
	return (1);
}
