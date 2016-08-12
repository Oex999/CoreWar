/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <owen@exall.za.net>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 14:24:35 by oexall            #+#    #+#             */
/*   Updated: 2016/08/12 09:28:51 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

char	*ft_trimsp(char *str)
{
	char	*end;

	while (*str == ' ' || *str == '\t')
		str++;
	end = str + ft_strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t'))
		end--;
	*(end + 1) = '\0';
	return (str);
}

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

char	*ft_text(char *line)
{
	char	*tmp;

	tmp = ft_strchr(line, '\"');
	return (ft_strdup(ft_trimquotes(tmp)));
}

t_arg_type	ft_get_type(char *str)
{
	if (str[0] == 'r')
		return (T_REG);
	else if (str[0] == '%')
		return (T_DIR);
	else
		return (T_IND);
	return (0);
}

void		ft_deltab(char **tab)
{
	int	i;

	if (tab)
	{
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}
