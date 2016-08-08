/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <owen@exall.za.net>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 13:00:01 by oexall            #+#    #+#             */
/*   Updated: 2016/08/08 10:05:45 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <op.h>
# include <fcntl.h>
# include <libft.h>

typedef enum		e_aliases
{
	UNKOWN = -1,
	NAME = 0,
	COMMENT = 1,
	LABEL = 2,
	CMD = 3
}					t_aliases;

typedef struct		s_input
{
	char			*line;
	int				alias;
	struct s_input	*prev;
	struct s_input	*next;
}					t_input;

t_input				*ft_new_elem(char *line, int alias);
void				ft_input_push_back(t_input **begin, char *line, int alias);
void				ft_input_free(t_input **input);

int					ft_err(char *str);
int					ft_check_file(char *file);
int					ft_get_alias(char *str);
int					ft_read_file(char *file, t_input *input);
#endif
