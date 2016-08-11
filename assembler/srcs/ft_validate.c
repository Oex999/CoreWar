/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 09:32:48 by oexall            #+#    #+#             */
/*   Updated: 2016/08/11 07:23:32 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			ft_validate(t_all *all)
{
	t_input	*list;

	list = all->input;
	if (list->alias != NAME || list->next->alias != COMMENT)
		return (ft_err("Requires .name & .comment to be first in line."));
	while (list)
	{
		if (list->alias == NAME && !ft_val_prog(list->line, &all->header))
			return (0);
		if (list->alias == COMMENT && !ft_val_comment(list->line, &all->header))
			return (0);
		if (list->alias == LABEL && !ft_val_label(list->line))
			return (0);
		if ((list->alias == CMD)
				&& !ft_val_cmd(list->line))
			return (0);
		list = list->next;
	}
	return (1);
}
