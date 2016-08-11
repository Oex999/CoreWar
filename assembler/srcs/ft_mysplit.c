/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mysplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 13:35:41 by oexall            #+#    #+#             */
/*   Updated: 2016/08/11 13:47:53 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int		ft_oneof(char c, char *in)
{
	int	i;

	i = -1;
	while (in[++i])
		if (c == in[i])
			return (i);
	return (0);
}

static int		ft_skipquotes(char **line)
{
	if (**line == '\"')
		(*line)++;
	while (**line != '\"')
		(*line)++;
	if (**line == '\"')
		(*line)++;
	return (1);
}

static int		ft_count_args(char *str, char *delim)
{
	int	c;
	int	in_w;

	c = 0;
	in_w = 0;
	while (*str)
	{
		if (*str == '\"')
			c += ft_skipquotes(&str);
		if (in_w == 0 && !ft_oneof(*str, delim))
			in_w = 1;
		if (in_w == 1 && (ft_oneof(*str, delim) || str[1] == '\0'))
		{
			in_w = 0;
			if (*str != '\0')
				c++;
		}
		str++;
	}
	return (c);
}

char		**ft_mysplit(char *str, char *delim)
{
	char	*start;
	char	**res;
	int		n_args;

	n_args = ft_count_args(str, delim);
	res = (char **)malloc(sizeof(char *) * (n_args + 1));
	start = str;
	while (*str)
	{
		if (*str == '\"')
			ft_skipquotes(&str);
		else if (ft_oneof(*str, delim))
		{
			if (start != str)
				*(res++) = ft_strsub(start, 0, str - start);
			start = (char *)str + 1;
		}
		str++;
	}
	if (start != str)
		*(res++) = ft_strsub(start, 0, str - start);
	*res = NULL;
	return (res - n_args);
}
