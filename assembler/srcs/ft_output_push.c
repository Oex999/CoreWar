/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <owen@exall.za.net>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 21:18:49 by oexall            #+#    #+#             */
/*   Updated: 2016/08/09 21:21:04 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	ft_output_push_back(t_output **begin, t_output *output)
{
	t_output	*list;

	list = *begin;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = output;
		list->next->prev = list;
	}
	else
		*begin = output;
}
