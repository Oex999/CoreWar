/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <owen@exall.za.net>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 07:37:41 by oexall            #+#    #+#             */
/*   Updated: 2016/08/11 14:38:08 by ghavenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <libft.h>
# include <op.h>

#define

typedef struct			s_process
{
	char				*champion_comment;
	int					*champion_id;
	int					alive;
	void				**registries;
	char				*pc;
	struct s_process	*next;
}						t_process;

typedef struct			s_address
{
	struct s_address	*previous;
	struct s_address	*next;
	char				*instruction;
	char				*address;
}						t_address;

typedef struct			s_state
{
	unsigned int		cycles_to_die;
	int					checks_done;
	t_address			*begin;
	t_process			**champions
}						t_state;

#endif
