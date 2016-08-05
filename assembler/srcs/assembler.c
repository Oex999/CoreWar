/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <owen@exall.za.net>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 12:49:16 by oexall            #+#    #+#             */
/*   Updated: 2016/08/05 12:49:03 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (ft_err("Usage: ./asm [file].s ..."));
	i = 1;
	while (argv[i])
	{
		if (!ft_checkfile(argv[i]))
			return (ft_err("Invalid file extension.\nUsage: [File].s"));
		ft_putendl(argv[i]); //DEBUG
		i++;
	}
	return (0);
}
