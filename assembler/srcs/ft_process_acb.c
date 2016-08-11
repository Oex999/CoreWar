/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_acb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <owen@exall.za.net>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 14:00:45 by oexall            #+#    #+#             */
/*   Updated: 2016/08/10 17:05:38 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

char	**ft_get_params(char *line)
{
	int		i;
	char	*tmp;
	char	**split;

	split = ft_strsplit(ft_strchr(line, ' '), SEPARATOR_CHAR);
	i = -1;
	while (split[++i])
	{
		tmp = ft_strdup(split[i]);
		free(split[i]);
		split[i] = ft_strdup(ft_trimspaces(tmp));
		free(tmp);
	}
	return (split);
}

char		*ft_process_acb(char *line)
{
	int		i;
	int		acb;
	char	**params;

	i = -1;
	acb = 0;
	params = ft_get_params(line);
	while (params[++i])
	{
		if (ft_get_type(params[i]) == T_REG)
			acb |= T_REG;
		else if (ft_get_type(params[i]) == T_DIR)
			acb |= T_DIR;
		else if (ft_get_type(params[i]) == T_IND)
			acb |= T_IND;
		acb = (int)(acb << 2);
	}
	ft_deltab(params);
	return (ft_itoa_base((int)acb, 16));
}
