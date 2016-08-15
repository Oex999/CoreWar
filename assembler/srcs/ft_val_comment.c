/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_comment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 10:26:52 by oexall            #+#    #+#             */
/*   Updated: 2016/08/13 11:36:22 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		ft_val_comment(char *comment, t_header *header)
{
	char	*tmp;

	tmp = ft_trimquotes(ft_strchr(comment, '\"'));
	ft_putstr("DEBUG: Line = "); ft_putendl(tmp); //DEBUG;
	if (ft_strlen(tmp) + 3 > COMMENT_LENGTH)
		return (ft_err("Comment is too long!"));
	ft_strcpy(header->comment, tmp);
	return (1);
}
