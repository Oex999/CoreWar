/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 10:58:10 by oexall            #+#    #+#             */
/*   Updated: 2016/08/11 10:07:58 by oexall           ###   ########.fr       */
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

static int	ft_check_params(char **params, int no_args, int index)
{
	t_arg_type	type;
	int			i;

	i = -1;
	while (++i < no_args)
	{
		type = g_op_tab[index].type[i];
		if ((ft_get_type(params[i]) & type) != ft_get_type(params[i]))
			return (0);
	}
	return (1);
}

int			ft_val_cmd(char *cmd)
{
	int		res;
	char	**params;
	int		no_args;
	int		index;

	res = 1;
	if ((index = ft_is_cmd(cmd)) == -1)
		return (ft_err("Invalid command."));
	no_args = g_op_tab[index].no_args;
	params = ft_strsplit(cmd, ' ');
	if (no_args != (ft_cargs(params) - 1))
		res = (ft_err("Invalid amount of parameters."));
	if (!ft_check_params(&params[1], no_args, index))
		res = (ft_err("Invalid parameter type."));
	ft_deltab(params);
	return (res);
}
