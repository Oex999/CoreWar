#ifndef VM_H
# define VM_H

# include <libft.h>
# include <op.h>
# include <fcntl.h>









#include <stdio.h> //DEBUG PURPOSES ONLY






# define REG process->registries
# define OP process->current_op.operation
# define ACB process->current_op.acb
# define ARG1 process->current_op.arg1
# define ARG2 process->current_op.arg2
# define ARG3 process->current_op.arg3
# define PC process->pc


/*----------------------------------------------------------------------------*/

//typedef unsigned char   t_u8;
typedef unsigned short  t_u16;
typedef unsigned int    t_u32;

typedef struct			s_address
{
	struct s_address	*next;
	int					operation;
	char				acb;
	int					arg1;
	int					arg2;
	int					arg3;
	int					address;
}						t_address;

typedef struct			s_process
{
	char				*champ_name;
	char				*champ_comment;
	int					champ_no;
    header_t            header;
    
    //for testing
    char                *p_c;
    //
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
	t_process			**champ;
	char				*live_champs;
	char				*prev_lc;
}						t_state;

/*---------------------------------------------------------------------------*/
/*init.c*/
void    	init_state(t_state *state);
void    	init_mem(t_state *state, t_address *current, int mem);
void    	init_process(t_process *process, int champ_no);
void    	init_reg(t_process *process);
void    	create_process(t_state *state, int champ_no);

/*free.c*/
/*free_process does not reconnect the end of the list*/
void    	free_state(t_state *state);
void    	free_reg(t_process *process);
void    	free_mem(t_address *current, int mem);
void	    free_process(t_process *process);
void        free_champ(t_process *champ);

/*input.c*/

/*exit.c*/
void        error_exit(t_state *state, char *message);

/*ft_itoabase.c ---TO BE ADDED TO LIBFT LATER*/
char        *ft_itoabase(int value, int base);

/*ft_puthex.c ---TO BE ADDED TO LIBFT LATER*/
void        ft_puthex(int value, int base);

/*parsing.c*/
void        parse_user_input(t_state *state, char **argv, int count);
int         parse_cycles_to_die(t_state *state, char **argv, int count);
int         parse_champ_count(t_state *state, char **argv, int count);
int         parse_champ_number(t_state *state, char **argv, int i, int count);
int         check_if_champs_assigned(t_state *state, char **argv);
int			ft_check_file(t_state *state, char **argv, int count);
int			parse_dump(t_state *state, char **argv, int i, int count);

/*gamecycles.c*/
void    	play_game(t_state *state);
void    	declare_champs(t_state *state);
void    	prune_champs(t_state *state);
void    	dump_memory(t_state *state);

/*gamechamps.c*/
void    	check_for_winner(t_state *state);
void    	run_champs(t_state *state);
void    	check_nbr_live(t_state *state);

/*operations.c*/
void    	complete_op1(t_state *state, t_process *process);
void    	complete_op2(t_state *state, t_process *process);
void    	set_op(t_process *process, int cycle_cost);
void    	start_op1(t_process *process);
void	    start_op2(t_process *process);


/*cmd1.c*/
void    	live(t_state *state, t_process *process);
void    	ld(t_state *state, t_process *process);
void    	st(t_process *process);
void    	add(t_process *process);
void	    sub(t_process *process);

/*cmd2.c*/
void    	and(t_state *state, t_process *process);
void    	or(t_state *state, t_process *process);
void    	xor(t_state *state, t_process *process);
void    	zjmp(t_state *state, t_process *process);
void    	ldi(t_state *state, t_process *process);

/*cmd3.c*/
void    	sti(t_state *state, t_process *process);
void    	cfork(t_state *state, t_process *process);
void    	lld(t_state *state, t_process *process);
void	    lldi(t_state *state, t_process *process);
void    	lfork(t_state *state, t_process *process);

/*cmd4.c*/
void    	aff(t_process *process);
t_address   *seek_address(t_state *state, t_address *mem, int address);
int         return_field(t_state *state, t_address *address, int field);
void        edit_field(t_state *state, t_address *address, int field, int new_value);

/*read.c*/
void		parse_champ_data(t_state *state, char *argv, int champ_no); // testing
void		check_magic(t_state *state, unsigned char *buff);
void        buffer_champion(unsigned char *buff, int fd);
void        deploy_champion(t_address *pc, unsigned char *buff);

/*ft_reverse_bytes.c*/
void		ft_reverse_bytes(void *mem, size_t size);

#endif
