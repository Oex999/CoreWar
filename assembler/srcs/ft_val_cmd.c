/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 10:58:10 by oexall            #+#    #+#             */
/*   Updated: 2016/08/09 11:31:21 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		ft_val_cmd(char *cmd)
{
	int	index;

	if ((index = ft_is_cmd(cmd)) == -1)
		return (ft_err("Invalid not found."));
	ft_putnbr(index);
	ft_putendl(" INDEX");
	return (1);
}
