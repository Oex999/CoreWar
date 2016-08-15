/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <owen@exall.za.net>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 07:37:41 by oexall            #+#    #+#             */
/*   Updated: 2016/08/15 18:17:59 by ghavenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <libft.h>
# include <op.h>









#include <stdio.h> //DEBUG PURPOSES ONLY






/*----------------------------------------------------------------------------*/

typedef struct			s_process
{
	char				*champion_comment;
	int					*champion_no;
	int					alive;
	int					carry;
	void				**registries;
	char				*pc;
	struct s_process	*next;
}						t_process;

typedef struct			s_address
{
	struct s_address	*next;
	int					instruction;
	char				*address;
}						t_address;

typedef struct			s_state
{
	unsigned int		cycles_to_die;
	int					checks_done;
	int					dump;
	t_address			*begin;
	t_process			**champions;
}						t_state;

/*----------------------------------------------------------------------------*/
/*init.c*/
void	init_state(t_state *state);
void	init_reg(t_process *process);
void	init_mem(t_state *state, t_address *current, int mem);
void	init_process(t_process *process);

/*free.c*/
void	free_state(t_state *state);
void	free_reg(t_process *process);
void	free_mem(t_address *current, int mem);
void	free_process(t_process *process);

/*input.c*/

/*ft_itoabase.c ---TO BE ADDED TO LIBFT LATER*/
char	*ft_itoabase(int value, int base);
#endif
