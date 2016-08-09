/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 10:39:53 by oexall            #+#    #+#             */
/*   Updated: 2016/08/09 10:54:11 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int	ft_oneof(char c)
{
	int	i;

	i = 0;
	if (c == ':')
		return (1);
	while (LABEL_CHARS[i] != '\0')
	{
		if (c == LABEL_CHARS[i])
			return (1);
		i++;
	}
	return (0);
}

int			ft_val_label(char *label)
{
	while (*label)
	{
		if (!ft_oneof(*label))
			return (ft_err("Invalid character in label"));
		label++;
	}
	return (1);
}
