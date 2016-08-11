/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 15:20:01 by oexall            #+#    #+#             */
/*   Updated: 2016/08/10 12:46:19 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_op	g_op_tab[17] =
{
	{"live", "01",1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", "02", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"sti", "0b", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"st", "03", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", "04", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", "05", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", "06", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", "07", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", "08", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", "09", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", "0a", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"fork", "0c", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", "0d", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", "0e", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", "0f", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", "10", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, 0, {0}, 0, 0, 0, 0, 0}
};
