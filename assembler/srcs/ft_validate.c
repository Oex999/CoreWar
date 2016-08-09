/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 09:32:48 by oexall            #+#    #+#             */
/*   Updated: 2016/08/09 11:31:03 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			ft_validate(t_input **input)
{
	t_input	*list;

	list = *input;
	while (list)
	{
		if (list->alias == NAME && !ft_val_prog(list->line))
			return (0);
		if (list->alias == COMMENT && !ft_val_comment(list->line))
			return (0);
		if (list->alias == LABEL && !ft_val_label(list->line))
			return (0);
		if ((list->alias == CMD || list->alias == UNKNOWN)
				&& !ft_val_cmd(list->line))
			return (0);
		list = list->next;
	}
	return (1);
}
