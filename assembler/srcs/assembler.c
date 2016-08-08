/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <owen@exall.za.net>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 12:49:16 by oexall            #+#    #+#             */
/*   Updated: 2016/08/08 13:51:44 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		main(int argc, char **argv)
{
	int		i;
	t_input	*input;

	if (argc < 2)
		return (ft_err("No Arguments.\nUsage: ./asm [*.s] ..."));
	i = 1;
	while (argv[i])
	{
		input = NULL;
		if (!(ft_check_file(argv[i])))
			break ;
		if (!(ft_read_file(argv[i], &input)))
			break ;
		ft_err(argv[i]);
		//DEBUG DEBUG DEBUG
		t_input	*tmp = input;
		while (tmp != NULL)
		{
			ft_putstr("LINE: ");
			ft_putendl(tmp->line);
			tmp = tmp->next;
		}
		//END   END   END
		ft_putendl("END");
		ft_input_free(&input);
		i++;
	}
	return (0);
}
