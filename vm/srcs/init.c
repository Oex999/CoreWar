/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaunder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 14:02:31 by bsaunder          #+#    #+#             */
/*   Updated: 2016/09/06 14:02:43 by bsaunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void			init_state(t_state *state)
{
	state->cycles_to_die = 0;
	state->champ_count = 0;
	state->dump = 0;
	state->live_champs = malloc(sizeof(char) * 5);
	ft_strcpy(state->live_champs, "0000");
	state->prev_lc = malloc(sizeof(char) * 5);
	ft_strcpy(state->prev_lc, "0000");
	printf("live_champs = %s\n", state->live_champs);
	state->begin = malloc(sizeof(t_address));
	init_mem(state, state->begin, MEM_SIZE * 5);
	state->champ = malloc(sizeof(t_process *) * 4);
}

void			init_mem(t_state *state, t_address *current, int mem)
{
	current->operation = 0;
	current->acb = 0;
	current->arg1 = 0;
	current->arg2 = 0;
	current->arg3 = 0;
	current->address = mem;
	if (mem <= 1)
		current->next = state->begin;
	else
	{
		current->next = malloc(sizeof(t_address));
		init_mem(state, current->next, mem - 5);
	}
}

void			create_process(t_state *state, int champ_no, char *file_name)
{
	t_process	*pointer;

	if (state->champ[champ_no - 1] != NULL)
	{
		pointer = state->champ[champ_no - 1];
		while (pointer->next != NULL)
			pointer = pointer->next;
		pointer->next = malloc(sizeof(t_process));
		init_process(pointer->next, champ_no);
		if (ft_strcmp(file_name, "NULL") != 0)
			parse_champ_data(state, file_name, champ_no);
	}
	else
	{
		state->champ[champ_no - 1] = malloc(sizeof(t_process));
		init_process(state->champ[champ_no - 1], champ_no);
		if (ft_strcmp(file_name, "NULL") != 0)
			parse_champ_data(state, file_name, champ_no);
	}
}

void			init_process(t_process *process, int champ_no)
{
	process->champ_name = malloc(sizeof(char) * PROG_NAME_LENGTH + 2);
	process->champ_name[PROG_NAME_LENGTH + 1] = '\0';
	process->champ_comment = malloc(sizeof(char) * COMMENT_LENGTH + 2);
	process->champ_comment[COMMENT_LENGTH + 1] = '\0';
	process->alive = 0;
	process->carry = 0;
	process->pc = NULL;
	process->current_op.operation = 0;
	process->cycles_to_execute = 0;
	process->ops_executed = 0;
	process->next = NULL;
	process->champ_no = champ_no;
	process->registries = malloc(sizeof(int *) * REG_NUMBER);
	init_reg(process);
}

void			init_reg(t_process *process)
{
	int			index;

	index = -1;
	while(++index != 16)
	{
		if (index == 0)
			process->registries[index] = process->champ_no;
		else
			process->registries[index] = 0;
	}
}
