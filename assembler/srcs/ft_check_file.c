/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 08:15:30 by oexall            #+#    #+#             */
/*   Updated: 2016/08/08 08:25:04 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		ft_check_file(char *file)
{
	int		fd;
	char	*tmp;

	tmp = ft_strrchr(file, '.');
	if (ft_strncmp(tmp, ".s", 1) != 0)
		return (ft_err("Invalid file extenstion"));
	if ((fd = open(file, O_WRONLY)) < 0)
		return (ft_err("Can't access file"));
	close(fd);
	return (1);
}
