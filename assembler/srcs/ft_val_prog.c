/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 10:04:21 by oexall            #+#    #+#             */
/*   Updated: 2016/08/13 11:30:44 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		ft_val_prog(char *prog, t_header *header)
{
	char	*tmp;

	tmp = ft_trimquotes(ft_strchr(prog, '\"'));
	ft_putstr("DEBUG: line = "); ft_putendl(tmp); //DEBUG
	if (ft_strlen(tmp) + 3 > PROG_NAME_LENGTH)
		return (ft_err("Program Name to long!"));
	ft_strcpy(header->prog_name, tmp);
	return (1);
}
