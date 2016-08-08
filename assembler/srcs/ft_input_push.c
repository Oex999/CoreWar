/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 08:53:50 by oexall            #+#    #+#             */
/*   Updated: 2016/08/08 11:43:05 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	ft_input_push_back(t_input **begin, char *line, int alias)
{
	t_input	*list;

	list = *begin;
	if (line && list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_new_elem(line, alias);
		list->next->prev = list;
	}
	else
		*begin = ft_new_elem(line, alias);
}
