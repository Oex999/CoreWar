/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 14:55:59 by oexall            #+#    #+#             */
/*   Updated: 2016/08/09 19:59:24 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static char	*ft_get_name(char *name)
{
	char	*tmp;
	char	*n_name;

	tmp = ft_strsub(name, 0, 
			ft_strlen(name) - ft_strlen(ft_strrchr(name, '.')));
	n_name = ft_strjoin(tmp, ".cor");
	free(tmp);
	return (n_name);
}

int			ft_print_file(t_all *all)
{
	int		res;
	char	*n_name;

	res = 1;
	n_name = ft_get_name(all->name);
	if ((all->fd = open(n_name, OPEN, 0644)) == -1)
		return (ft_err("Failed to create .cor file"));
	if (!ft_print_name(all))
		res = ft_err("Failed to write .name to file.");
	if (close(all->fd) == -1)
		return (ft_err("Failed to close .cor file."));
	free(n_name);
	return (res);
}
