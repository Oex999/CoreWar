/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 08:42:07 by oexall            #+#    #+#             */
/*   Updated: 2016/08/09 08:49:14 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static char	*ft_get_str(char *ptr)
{
	int		i;
	char	*str;

	i = 0;
	while (ptr[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	i = -1;
	while (ptr[++i] != '\0')
		str[i] = ptr[i];
	return (str);
}

char		*ft_itoa_base(int value, int base)
{
	int			minus;
	long int	num;
	char		buffer[50];
	char		*ptr;

	minus = 0;
	num = value;
	ptr = &buffer[49];
	*ptr = '\0';
	if (value < 0)
	{
		num *= -1;
		minus = 1;
	}
	if (value == 0)
		*--ptr = '0';
	while (num != 0)
	{
		*--ptr = "0123456789abcdef"[num % base];
		num /= base;
	}
	if (base == 10 && minus == 1)
		*--ptr = '-';
	return (ft_get_str(ptr));
}
