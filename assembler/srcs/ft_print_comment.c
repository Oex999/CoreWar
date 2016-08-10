/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <owen@exall.za.net>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:05:41 by oexall            #+#    #+#             */
/*   Updated: 2016/08/10 16:28:28 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static void	ft_print_pad(t_all *all, int total)
{
	while (total < COMMENT_LENGTH)
	{
		write(all->fd, "00", 2);
		if (total % 2)
			write(all->fd, " ", 1);
		total++;
	}
}

int		ft_print_comment(t_all *all)
{
	int		i;
	int		t;
	char	*comment;

	i = -1;
	t = -1;
	comment = ft_text(all->input->next->line);
	while (++t < 10)
	{
		write(all->fd, "00", 2);
		if (t % 2)
			write(all->fd, " ", 1);
	}
	ft_putendl(comment);
	while (comment[++i])
	{
		write(all->fd, ft_itoa_base((int)comment[i], 16), 2);
		if (i % 2)
			write(all->fd, " ", 1);
	}
	ft_print_pad(all, t + i);
	free(comment);
	return (1);
}
