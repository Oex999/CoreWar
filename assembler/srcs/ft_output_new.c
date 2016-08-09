/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <owen@exall.za.net>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 21:14:00 by oexall            #+#    #+#             */
/*   Updated: 2016/08/09 21:16:29 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_output	*ft_output_new(void)
{
	t_output	*tmp;

	tmp = (t_output *)malloc(sizeof(t_output));
	tmp->opcode = NULL;
	tmp->acb = NULL;
	tmp->arg1 = NULL;
	tmp->arg2 = NULL;
	tmp->arg3 = NULL;
	tmp->arg3 = NULL;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}
