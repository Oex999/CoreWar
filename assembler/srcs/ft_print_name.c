/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 15:38:18 by oexall            #+#    #+#             */
/*   Updated: 2016/08/09 21:18:34 by oexall           ###   ########.fr       */
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

int		ft_print_name(t_all *all)
{
	int		i;
	char	*name;

	write(all->fd, "00ea 83f3 ", 10);
	i = 0;
	name = ft_text(all->input->line);
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
