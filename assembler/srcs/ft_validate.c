/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 09:32:48 by oexall            #+#    #+#             */
/*   Updated: 2016/08/13 11:37:36 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			ft_validate(t_all *all)
{
	t_input	*list;

	list = all->input;
	ft_putendl("DEBUG: Validating"); //DEBUG
	if (list->alias != NAME || list->next->alias != COMMENT)
		return (ft_err("Requires .name & .comment to be first in line."));
	while (list)
	{
		ft_putendl("DEBUG: Validating Row."); //DEBUG
		if (list->alias == NAME && !ft_val_prog(list->line, &all->header))
			return (0);
		ft_putendl("DEBUG: Validated Name."); //DEBUG
		if (list->alias == COMMENT && !ft_val_comment(list->line, &all->header))
			return (0);
		ft_putendl("DEBUG: Validated Comment."); //DEBUG
		if (list->alias == LABEL && !ft_val_label(list->line, 1))
			return (0);
		ft_putendl("DEBUG: Validated Label."); //DEBUG
		if ((list->alias == CMD) && !ft_val_cmd(list->line))
			return (0);
		ft_putendl("DEBUG: Validated Command."); //DEBUG
		list = list->next;
		ft_putendl("DEBUG: NEXT LINE; NEXT LINE"); //DEBUG
	}
	ft_putendl("DEBUG: Validated."); //DEBUG
	return (1);
}
