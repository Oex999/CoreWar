/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 15:38:18 by oexall            #+#    #+#             */
/*   Updated: 2016/08/11 10:01:18 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int	ft_print_magic(t_all *all)
{
	int			t;
	int			i;
	char		*str;

	i = -1;
	str = ft_itoa_base(all->header.magic, 16);
	if ((ft_strlen(str) % 4) != 0)
		while ((ft_strlen(str) + (++i)) % 4 != 0)
			write(all->fd, "0", 1);
	t = i;
	i = 0;
	while (str[i])
	{
		write(all->fd, &str[i], 2);
		if (t % 4)
			write(all->fd, " ", 1);
		i += 2;
		t += 2;
	}
	return (t);
}

int		ft_print_name(t_all *all)
{
	int		t;
	int		i;
	char	*name;

	i = 0;
	name = all->header.prog_name;
	t = ft_print_magic(all);
	while (name[i])
	{
		write(all->fd, ft_itoa_base((int)name[i], 16), 2);
		if (i % 2)
			write(all->fd, " ", 1);
		i++;
	}
	while ((t - 4 + i) < PROG_NAME_LENGTH)
	{
		write(all->fd, "00", 2);
		if (i % 2)
			write(all->fd, " ", 1);
		i++;
	}
	return (1);
}
