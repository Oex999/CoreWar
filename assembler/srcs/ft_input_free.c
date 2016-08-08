/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 10:04:12 by oexall            #+#    #+#             */
/*   Updated: 2016/08/08 10:08:57 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	ft_input_free(t_input **input)
{
	t_input	*list;
	t_input	*tmp;

	list = *input;
	if (list)
	{
		while (list)
		{
			tmp = list;
			list = tmp->next;
			tmp->next = NULL;
			tmp->prev = NULL;
			if (list->line)
				free(list->line);
			list->alias = 0;
			free(tmp);
		}
	}
}
