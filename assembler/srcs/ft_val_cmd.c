/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 10:58:10 by oexall            #+#    #+#             */
/*   Updated: 2016/08/09 12:23:06 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int	ft_cargs(char **params)
{
	int	i;

	i = 0;
	while (params[i])
		i++;
	return (i);
}

int			ft_val_cmd(char *cmd)
{
	char	**params;
	int		no_args;
	int		index;

	if ((index = ft_is_cmd(cmd)) == -1)
		return (ft_err("Invalid not found."));
	no_args = g_op_tab[index].no_args;
	params = ft_strsplit(cmd, ' ');
	if (no_args != (ft_cargs(params) - 1))
		return (ft_err("Invalid amount of arguments"));
	ft_deltab(params);
	return (1);
}
