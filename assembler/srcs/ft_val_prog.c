/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 10:04:21 by oexall            #+#    #+#             */
/*   Updated: 2016/08/11 13:50:57 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		ft_val_prog(char *prog, t_header *header)
{
	int		len;
	char	**split;

	split = ft_mysplit(prog, DELIM);
	if (!split[1])
		return (ft_err("Failed to dectect Champion Name"));
	ft_strcpy(header->prog_name, ft_trimquotes(split[1]));
	len = ft_strlen(header->prog_name);
	if ((len + 3) > PROG_NAME_LENGTH)
		return (ft_err("Champion Name is too long"));
	ft_deltab(split);
	return (1);
}
