/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <owen@exall.za.net>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 12:32:48 by oexall            #+#    #+#             */
/*   Updated: 2016/08/10 12:50:31 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		ft_process_input(t_all *all)
{
	t_input		*input;
	t_output	*n_out;

	input = all->input;
	while (input)
	{
		if (input->alias == CMD)
		{
			n_out = ft_output_new();
			n_out->opcode = g_op_tab[ft_is_cmd(input->line)].opcode;
			ft_putendl(n_out->opcode); //DEBUG
		}
		input = input->next;
	}
	return (1);
}
