/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <owen@exall.za.net>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 12:49:16 by oexall            #+#    #+#             */
/*   Updated: 2016/08/09 09:42:10 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		main(int argc, char **argv)
{
	int		i;
	t_all	all;

	if (argc < 2)
		return (ft_err("No Arguments.\nUsage: ./asm [*.s] ..."));
	i = 1;
	while (argv[i])
	{
		all.input = NULL;
		all.name = argv[i];
		if (!(ft_check_file(argv[i])))
			break ;
		if (!(ft_read_file(argv[i], &all.input)))
			break ;
		if (!(ft_validate(&all.input)))
			break ;
		ft_err(argv[i]); //DEBUG
		//DEBUG DEBUG DEBUG
		t_input	*tmp = all.input;
		while (tmp != NULL)
		{
			ft_putstr("Alias: ");
			ft_putnbr(tmp->alias);
			ft_putstr("\nLINE: ");
			ft_putendl(tmp->line);
			tmp = tmp->next;
		}
		//END   END   END
		ft_putendl("END"); //DEBUG
		ft_input_free(&all.input);
		i++;
	}
	return (0);
}
