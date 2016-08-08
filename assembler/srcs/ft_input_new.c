/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 08:47:52 by oexall            #+#    #+#             */
/*   Updated: 2016/08/08 12:56:39 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_input	*ft_new_elem(char *line, int alias)
{
	t_input	*tmp;

	tmp = (t_input *)malloc(sizeof(t_input));
	tmp->line = ft_strdup(line);
	tmp->alias = alias;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}
