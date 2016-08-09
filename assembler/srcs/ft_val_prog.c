/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 10:04:21 by oexall            #+#    #+#             */
/*   Updated: 2016/08/09 10:23:45 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

char	*ft_trimquotes(char *str)
{
	char	*end;

	while (*str == '\"')
		str++;
	end = str + ft_strlen(str) - 1;
	while (end > str && *end == '\"')
		end--;
	*(end + 1) = '\0';
	return (str);
}

int		ft_val_prog(char *prog)
{
	int		len;
	char	*tmp;
	char	**split;

	split = ft_strsplit(prog, ' ');
	if (!split[1])
		return (ft_err("Failed to dectect Champion Name"));
	tmp = split[1];
	free(split[1]);
	split[1] = ft_strdup(ft_trimquotes(tmp));
	len = ft_strlen(split[1]);
	if ((len + 3) > PROG_NAME_LENGTH)
		return (ft_err("Champion Name is too long"));
	ft_deltab(split);
	return (1);
}
