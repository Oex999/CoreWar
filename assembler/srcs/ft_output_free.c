/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <owen@exall.za.net>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 21:21:58 by oexall            #+#    #+#             */
/*   Updated: 2016/08/10 13:28:26 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	ft_output_free(t_output **output)
{
	t_output	*list;
	t_output	*tmp;

	list = *output;
	if (list)
	{
		while (list != NULL)
		{
			tmp = list;
			list = list->next;
			if (tmp->acb)
				free(tmp->acb);
			if (tmp->arg1)
				free(tmp->arg1);
			if (tmp->arg2)
				free(tmp->arg2);
			if (tmp->arg3)
				free(tmp->arg3);
			if (tmp->arg4)
				free(tmp->arg4);
			tmp->prev = NULL;
			tmp->next = NULL;
		}
	}
}
