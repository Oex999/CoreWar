/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 07:52:13 by oexall            #+#    #+#             */
/*   Updated: 2016/08/12 09:27:33 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		ft_is_cmd(char *str)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (ft_strncmp(str, g_op_tab[i].name, ft_strlen(g_op_tab[i].name)) == 0)
			return (i);
		i++;
	}
	return (0);
}

void	ft_format(char ***tab)
{
	char	**split;
	char	*tmp;
	int		i;

	i = 0;
	split = *tab;
	tmp = NULL;
	while (split[i])
	{
		tmp = ft_strdup(ft_trimsp(split[i]));
		free(split[i]);
		split[i] = ft_strdup(tmp);
		free(tmp);
		i++;
	}
}
