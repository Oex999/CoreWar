/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 09:32:48 by oexall            #+#    #+#             */
/*   Updated: 2016/08/09 10:52:31 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			ft_validate(t_input **input)
{
	t_input	*list;

	list = *input;
	while (list)
	{
		if (list->alias == 0 && !ft_val_prog(list->line))
			return (0);
		if (list->alias == 1 && !ft_val_comment(list->line))
			return (0);
		if (list->alias == 2 && !ft_val_label(list->line))
			return (0);
		list = list->next;
	}
	return (1);
}
