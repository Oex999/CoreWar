/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_comment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 10:26:52 by oexall            #+#    #+#             */
/*   Updated: 2016/08/09 10:37:52 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		ft_val_comment(char *comment)
{
	int		len;
	char	*tmp;
	char	**split;

	split = ft_strsplit(comment, ' ');
	if (!split[1])
		return (ft_err("Failed to detect Champion Comment."));
	tmp = split[1];
	free(split[1]);
	split[1] = ft_strdup(ft_trimquotes(tmp));
	len = ft_strlen(split[1]);
	if ((len + 3) > COMMENT_LENGTH)
		return (ft_err("Champion Comment is too long"));
	ft_deltab(split);
	return (1);
}
