/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <owen@exall.za.net>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 13:00:01 by oexall            #+#    #+#             */
/*   Updated: 2016/08/09 15:40:25 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <op.h>
# include <fcntl.h>
# include <libft.h>

# define OPEN O_WRONLY | O_CREAT | O_TRUNC

typedef enum		e_aliases
{
	UNKNOWN = -1,
	NAME = 0,
	COMMENT = 1,
	LABEL = 2,
	CMD = 3,
}					t_aliases;

typedef struct		s_input
{
	char			*line;
	int				alias;
	struct s_input	*prev;
	struct s_input	*next;
}					t_input;

typedef struct		s_all
{
	int				fd;
	char			*name;
	t_input			*input;
}					t_all;

t_input				*ft_new_elem(char *line, int alias);
void				ft_input_push_back(t_input **begin, char *line, int alias);
void				ft_input_free(t_input **input);

int					ft_err(char *str);
int					ft_check_file(char *file);
void				ft_deltab(char **tab);
int					ft_is_cmd(char *str);
int					ft_get_alias(char *str);
int					ft_read_file(char *file, t_input **input);

char				*ft_trimquotes(char *str);
int					ft_val_cmd(char *cmd);
int					ft_val_label(char *label);
int					ft_val_comment(char *comment);
int					ft_val_prog(char *prog);
int					ft_validate(t_input **input);

char				*ft_itoa_base(int value, int base);

int					ft_print_name(char *line);
int					ft_print_file(t_all *all);
#endif
