/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 15:38:18 by oexall            #+#    #+#             */
/*   Updated: 2016/08/10 10:23:58 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

char	*ft_text(char *line)
{
	char	*tmp;
	char	**split;

	split = ft_strsplit(line, ' ');
	tmp = ft_strdup(ft_trimquotes(split[1]));
	ft_deltab(split);
	return (tmp);
}

static int	ft_print_magic(int fd)
{
	int			t;
	int			i;
	char		*str;

	i = -1;
	str = ft_itoa_base((int)(COREWAR_EXEC_MAGIC), 16);
	if ((ft_strlen(str) % 4) != 0)
		while ((ft_strlen(str) + (++i)) % 4 != 0)
			write(fd, "0", 1);
	t = i;
	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 2);
		if (t % 4)
			write(fd, " ", 1);
		i += 2;
		t += 2;
	}
	free(str);
	return (t);
}

int		ft_print_name(t_all *all)
{
	int		i;
	char	*name;

	i = 0;
	name = ft_text(all->input->line);
	ft_print_magic(all->fd);
	while (name[i])
	{
		write(all->fd, ft_itoa_base((int)name[i], 16), 2);
		if (i % 2)
			write(all->fd, " ", 1);
		i++;
	}
	while (i < 124)
	{
		write(all->fd, "00", 2);
		if (i % 2)
			write(all->fd, " ", 1);
		i++;
	}
	free(name);
	return (1);
}
