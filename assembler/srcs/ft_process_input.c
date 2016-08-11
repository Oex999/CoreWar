/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <owen@exall.za.net>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 12:32:48 by oexall            #+#    #+#             */
/*   Updated: 2016/08/11 12:57:40 by oexall           ###   ########.fr       */
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
			if (ft_strncmp(input->line, "fork", 4) != 0 && 
					ft_strncmp(input->line, "zjmp", 4) != 0 &&
					ft_strncmp(input->line, "live", 4) != 0)
				n_out->acb = ft_process_acb(input->line);
			if (!ft_process_args(all, &n_out, input->line))
				return (ft_err("Failed to process arguments."));

			ft_putstr(n_out->opcode); //DEBUG
			ft_putstr(" "); //DEBUG
			ft_putstr((n_out->acb) ? n_out->acb : ""); ft_putstr(" ");//DEBUG
			ft_putstr((n_out->arg1) ? n_out->arg1 : ""); ft_putstr(" ");//DEBUG
			ft_putstr((n_out->arg2) ? n_out->arg2 : ""); ft_putstr(" "); //DEBUG
			ft_putendl((n_out->arg3) ? n_out->arg3 : "");//DEBUG
		}
		input = input->next;
	}
	return (1);
}
