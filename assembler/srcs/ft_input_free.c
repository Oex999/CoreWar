/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 10:04:12 by oexall            #+#    #+#             */
/*   Updated: 2016/08/08 13:46:47 by oexall           ###   ########.fr       */
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
		while (list != NULL)
		{
			tmp = list;
			list = list->next;
			tmp->next = NULL;
			tmp->prev = NULL;
			free(tmp->line);
			free(tmp);
		}
	}
}
