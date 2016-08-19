#ifndef VM_H
# define VM_H

# include <libft.h>
# include <op.h>
# include <fcntl.h>









#include <stdio.h> //DEBUG PURPOSES ONLY






/*----------------------------------------------------------------------------*/

typedef struct			s_process
{
	char				*champion_name;
	char				*champion_comment;
	int					champion_no;
	int					alive;
	int					carry;
	int					*registries;
	char				*pc;
	int					has_next;
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
	int					champ_count;
	int					checks_done;
	int					dump;
	t_address			*begin;
	t_process			**champions;
	char				*live_champs;
}						t_state;

/*----------------------------------------------------------------------------*/
/*init.c*/
void	init_state(t_state *state);
void	init_mem(t_state *state, t_address *current, int mem);
void	init_process(t_process *process, int champion_no);
void	init_reg(t_process *process);
void	create_process(t_state *state, int champion_no);

/*free.c --- free_process does not reconnect the end of the list*/
void	free_state(t_state *state);
void	free_reg(t_process *process);
void	free_mem(t_address *current, int mem);
void	free_process(t_process *process);
void	free_champion(t_process *champion);

/*input.c*/

/*exit.c*/
void	error_exit(t_state *state, char *message);

/*ft_itoabase.c ---TO BE ADDED TO LIBFT LATER*/
char	*ft_itoabase(int value, int base);

/*parsing.c*/
void    parse_user_input(t_state *state, char **argv, int count);
int     parse_cycles_to_die(t_state *state, char **argv, int count);
int     parse_champ_count(t_state *state, char **argv, int count);
int     parse_champ_number(t_state *state, char **argv, int count); //implement once champions setup
int     check_if_champs_assigned(t_state *state, int left);

#endif
