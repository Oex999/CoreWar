/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaunder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 13:25:41 by bsaunder          #+#    #+#             */
/*   Updated: 2016/09/06 13:42:36 by bsaunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

long int		ft_pow(int base, int power)
{
	long int	pow;
	int			index;

	index = -1;
	pow = base;
	while (++index <= power)
		pow *= pow;
	return (pow);
}
