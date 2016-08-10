/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <owen@exall.za.net>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 13:00:01 by oexall            #+#    #+#             */
/*   Updated: 2016/08/10 17:06:06 by oexall           ###   ########.fr       */
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

typedef struct		s_output
{
	char			*opcode;
	char			*acb;
	char			*arg1;
	char			*arg2;
	char			*arg3;
	char			*arg4;
	struct s_output	*prev;
	struct s_output	*next;
}					t_output;

typedef struct		s_all
{
	int				fd;
	char			*name;
	t_input			*input;
	t_output		*output;
}					t_all;

t_input				*ft_new_elem(char *line, int alias);
void				ft_input_push_back(t_input **begin, char *line, int alias);
void				ft_input_free(t_input **input);

t_output			*ft_output_new(void);
void				ft_output_push_back(t_output **begin, t_output *output);
void				ft_output_free(t_output **output);

char				**ft_get_params(char *line);
char				*ft_process_acb(char *line);
int					ft_process_input(t_all *all);

char				*ft_trimspaces(char *str);
int					ft_err(char *str);
int					ft_check_file(char *file);
void				ft_deltab(char **tab);
int					ft_is_cmd(char *str);
int					ft_get_alias(char *str);
int					ft_read_file(char *file, t_input **input);

t_arg_type			ft_get_type(char *str);
char				*ft_trimquotes(char *str);
int					ft_val_cmd(char *cmd);
int					ft_val_label(char *label);
int					ft_val_comment(char *comment);
int					ft_val_prog(char *prog);
int					ft_validate(t_input **input);

char				*ft_itoa_base(int value, int base);

char				*ft_text(char *line);
int					ft_print_name(t_all *all);
int					ft_print_comment(t_all *all);
int					ft_print_file(t_all *all);
#endif
