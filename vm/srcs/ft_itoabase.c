/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghavenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 07:33:26 by ghavenga          #+#    #+#             */
/*   Updated: 2016/08/15 10:25:55 by ghavenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>
#include <libc.h>

char		*get_str(char *ptr)
{
	int		i;
	char	*str;

	i = 0;
	while (ptr[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (ptr[i] != 0)
	{
		str[i] = ptr[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_itoabase(int value, int base)
{
	char		buf[50];
	char		*ptr;
	long int	num;
	int			minus;

	minus = 0;
	ptr = &buf[49];
	*ptr = '\0';
	num = value;
	if (value < 0)
	{
		num *= -1;
		minus = 1;
	}
	if (num == 0)
		*--ptr = '0';
	while (num != 0)
	{
		*--ptr = "0123456789ABCDEF"[num % base];
		num /= base;
	}
	if (minus == 1 && base == 10)
		*--ptr = '-';
	return (get_str(ptr));
}
