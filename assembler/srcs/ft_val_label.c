/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 10:39:53 by oexall            #+#    #+#             */
/*   Updated: 2016/08/13 11:41:04 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			ft_val_label(char *label, int visible)
{
	int	i;

	i = 0;
	ft_putstr("DEBUG: Label -> "); ft_putendl(label);
	while (label[i])
	{
		if (label[i] == ':' && label[i - 1] == '%')
			return (visible ? ft_err("Invalid Label.") : 0);
		if (!ft_oneof(label[i], LABEL_CHARS) && label[i] != ':')
			return (visible ? ft_err("Invalid Label.") : 0);
		i++;
	}
	return (1);
}
