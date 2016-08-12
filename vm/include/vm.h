/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <owen@exall.za.net>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 07:37:41 by oexall            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/08/12 15:08:52 by ghavenga         ###   ########.fr       */
=======
/*   Updated: 2016/08/11 15:41:35 by sallen           ###   ########.fr       */
>>>>>>> 5788d9acdc24708364e7d3381908cab03e1a41d8
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <libft.h>
# include <op.h>

<<<<<<< HEAD
/*----------------------------------------------------------------------------*/

=======
>>>>>>> 5788d9acdc24708364e7d3381908cab03e1a41d8
typedef struct			s_process
{
	char				*champion_comment;
	int					*champion_id;
	int					alive;
	int					carry;
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
	t_process			**champions;
}						t_state;

<<<<<<< HEAD
/*----------------------------------------------------------------------------*/
/*init.c*/
void	init_state(t_state *state);
void	init_reg(t_process *process);
void	init_mem(t_address *previous, t_address *current, int mem);
void	init_process(t_process *process);
=======
/*==== FUNCTIONS ==== */

void	**init_reg(t_process *process);
>>>>>>> 5788d9acdc24708364e7d3381908cab03e1a41d8

#endif
