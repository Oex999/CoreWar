/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghavenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 08:31:02 by ghavenga          #+#    #+#             */
/*   Updated: 2016/09/06 13:29:41 by bsaunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		ft_puthex(int number)
{
	char	*str;

	str = ft_itoabase(number, 16);
	ft_putstr(str);
	free(str);
}
