/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <owen@exall.za.net>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 21:21:58 by oexall            #+#    #+#             */
/*   Updated: 2016/08/09 21:30:36 by oexall           ###   ########.fr       */
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
			free(tmp->opcode);
			free(tmp->acb);
			free(tmp->arg1);
			free(tmp->arg2);
			free(tmp->arg3);
			free(tmp->arg4);
			tmp->prev = NULL;
			tmp->next = NULL;
		}
	}
}
