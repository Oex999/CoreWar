#ifndef VM_H
# define VM_H

# include <libft.h>
# include <op.h>
# include <fcntl.h>









#include <stdio.h> //DEBUG PURPOSES ONLY






/*----------------------------------------------------------------------------*/

typedef struct			s_address
{
	struct s_address	*next;
	int					operation;
	char				acb;
	int					arg1;
	int					arg2;
	int					arg3;
	int					arg4;
	int					address;
}						t_address;

typedef struct			s_process
{
	char				*champion_name;
	char				*champion_comment;
	int					champion_no;
	int					alive;
	int					carry;
	int					*registries;
	t_address			*pc;
	t_address			current_op;
	int					cycles_to_execute;
	int					ops_executed;
	struct s_process	*next;
}						t_process;

typedef struct			s_state
{
	unsigned int		cycles_to_die;
	int					champ_count;
    int                 occupied;
	int					dump;
	t_address			*begin;
	t_process			**champions;
	char				*live_champs;
	char				*prev_lc;
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

/*ft_puthex.c ---TO BE ADDED TO LIBFT LATER*/
void	ft_puthex(int value, int base);

/*parsing.c*/
void    parse_user_input(t_state *state, char **argv, int count);
int     parse_cycles_to_die(t_state *state, char **argv, int count);
int     parse_champ_count(t_state *state, char **argv, int count);
int     parse_champ_number(t_state *state, char **argv, int i, int count); //implement once champions setup
int     check_if_champs_assigned(t_state *state);

/*gamecycles.c*/
void	play_game(t_state *state);
void	declare_champs(t_state *state);
void	prune_champs(t_state *state);
void	dump_memory(t_state *state);

/*gamechamps.c*/
void	check_for_winner(t_state *state);
void	run_champs(t_state *state);
void	check_nbr_live(t_state *state);

/*operations.c*/
void	complete_op1(t_state *state, t_process *process);
void	complete_op2(t_process *process);
void	set_op(t_process *process, int cycle_cost);
void	start_op1(t_process *process);
void	start_op2(t_process *process);


/*cmd1.c*/
void	live(t_state *state, t_process *process);
void	ld(t_process *process);
void	st(t_process *process);
void	add(t_process *process);
void	sub(t_process *process);

/*cmd2.c*/
void	and(t_process *process);
void	or(t_process *process);
void	xor(t_process *process);
void	zjmp(t_process *process);
void	ldi(t_process *process);

/*cmd3.c*/
void	sti(t_process *process);
void	cfork(t_process *process);
void	lld(t_process *process);
void	lldi(t_process *process);
void	lfork(t_process *process);

/*cmd4.c*/
void	aff(t_process *process);

#endif
