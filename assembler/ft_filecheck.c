/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filecheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <owen@exall.za.net>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 13:06:54 by oexall            #+#    #+#             */
/*   Updated: 2016/08/03 13:13:38 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_checkfile(char *file)
{
	int	res;

	res = 1;
	if (ft_strncmp(ft_strrchr(file, '.'), ".s", 2) != 0)
		return (0);
	return (res);
}
