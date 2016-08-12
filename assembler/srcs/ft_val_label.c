/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 10:39:53 by oexall            #+#    #+#             */
/*   Updated: 2016/08/12 09:16:48 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			ft_val_label(char *label, int visible)
{
	int	i;

	i = 0;
	while (label[i])
	{
		if (label[i] == ':' && label[i - 1] == '%')
			return (visible ? ft_err("Invalid Label.") : 0);
		if (!ft_oneof(label[i], LABEL_CHARS))
			return (visible ? ft_err("Invalid Label.") : 0);
		i++;
	}
	return (1);
}
