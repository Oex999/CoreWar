/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_comment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 10:26:52 by oexall            #+#    #+#             */
/*   Updated: 2016/08/11 13:51:38 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		ft_val_comment(char *comment, t_header *header)
{
	int		len;
	char	**split;

	split = ft_mysplit(comment, DELIM);
	if (!split[1])
		return (ft_err("Failed to detect Champion Comment."));
	ft_strcpy(header->comment, ft_text(comment));
	len = ft_strlen(header->comment);
	if ((len + 3) > COMMENT_LENGTH)
		return (ft_err("Champion Comment is too long"));
	ft_deltab(split);
	return (1);
}
