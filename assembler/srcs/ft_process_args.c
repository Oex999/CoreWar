/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 09:07:45 by oexall            #+#    #+#             */
/*   Updated: 2016/08/12 09:27:17 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static char	*ft_resolve_reg(char *reg)
{
	int		val;
	char	*tmp;
	char	*join;

	val = 0;
	join = NULL;
	tmp = NULL;
	val = ft_atoi(&reg[1]);
	tmp = ft_itoa_base(val, 16);
	if (ft_strlen(tmp) < 2)
		join = ft_strjoin("0", tmp);
	if (join)
		free(tmp);
	return ((join) ? join : tmp);
}

static char	*ft_resolve_dir(char *dir)
{
	int		val;
	char	*tmp;
	char	*join;

	tmp = NULL;
	join = NULL;
	if (dir[1] == ':')
		return ("SOME"); //TO-DO
	else
		val = ft_atoi(&dir[1]);
	if (val == 0)
		return ("00 00 00 00");
	tmp = ft_itoa_base(val, 16);
	if (ft_strlen(tmp) < 2)
		join = ft_strjoin("0", tmp);
	if (join)
		free(tmp);
	return ((join) ? join : tmp);
}

static char	*ft_get_arg(char *line)
{
	if (ft_get_type(ft_trimsp(line)) == T_REG)
		return (ft_resolve_reg(ft_trimsp(line)));
	else if (ft_get_type(ft_trimsp(line)) == T_DIR)
		return (ft_resolve_dir(ft_trimsp(line)));
	else if (ft_get_type(ft_trimsp(line)) == T_IND)
		return ("IND"); //TO-DO
	return (NULL);
}

int		ft_process_args(t_all *all, t_output **node, char *line)
{
	int		i;
	char	**params;
	
	i = 0;
	(void)all; //DEBUG
	params = ft_get_params(line);
	while (params[i])
	{
		if (i == 0)
			(*node)->arg1 = ft_get_arg(params[i]);
		else if (i == 1)
			(*node)->arg2 = ft_get_arg(params[i]);
		else if (i == 2)
			(*node)->arg3 = ft_get_arg(params[i]);
		else if (i == 3)
			(*node)->arg4 = ft_get_arg(params[i]);
		i++;
	}
	ft_deltab(params);
	return (1);
}	
