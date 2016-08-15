/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <owen@exall.za.net>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 12:49:16 by oexall            #+#    #+#             */
/*   Updated: 2016/08/13 11:08:33 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	ft_init(t_all *all)
{
	all->input = NULL;
	all->output = NULL;
	all->header.magic = COREWAR_EXEC_MAGIC;
}

int		main(int argc, char **argv)
{
	int		i;
	t_all	all;

	if (argc < 2)
		return (ft_err("No Arguments.\nUsage: ./asm [*.s] ..."));
	i = 0;
	ft_init(&all);
	while (argv[++i])
	{
		all.name = argv[i];
		if (!(ft_check_file(argv[i])))
			break ;
		if (!(ft_read_file(argv[i], &all.input)))
			break ;
		if (!(ft_validate(&all)))
			break ;
		/*if (!(ft_process_input(&all)))
			break ;
		if (!(ft_print_file(&all)))
			break ;*/

		ft_err(argv[i]); //DEBUG
		//DEBUG DEBUG DEBUG
		t_input	*tmp = all.input;
		while (tmp != NULL)
		{
			ft_putstr("ALIAS: ");
			ft_putnbr(tmp->alias);
			ft_putstr("\tLINE: ");
			ft_putendl(tmp->line);
			tmp = tmp->next;
		}
		//END   END   END
		ft_putendl("END"); //DEBUG

		ft_input_free(&all.input);
		ft_output_free(&all.output);
	}
	return (0);
}
