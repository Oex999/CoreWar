# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghavenga <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/04 07:37:46 by ghavenga          #+#    #+#              #
#    Updated: 2016/08/31 06:59:45 by oexall           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= asm

CC= gcc -o
CFLAGS= -Wall -Werror -Wextra
LIBFT= -L libft/ -lft
HEADER= -I ./include -I libft

SP= ./srcs/
SRC= $(SP)main.c $(SP)ft_error.c $(SP)ft_list.c $(SP)ft_misc_one.c $(SP)op.c \
	 $(SP)ft_list_cmd.c $(SP)ft_misc_two.c \
	 $(SP)ft_read_check.c $(SP)ft_read_file.c \
	 $(SP)ft_validate.c $(SP)ft_val_label.c $(SP)ft_is_valid.c \
	 $(SP)ft_print.c $(SP)ft_print_name.c $(SP)ft_print_cmds.c \
	 $(SP)ft_print_params.c $(SP)ft_print_lbl.c $(SP)ft_check_digit.c

all: $(NAME)

$(NAME):
	@clear
	@echo "\x1b[31m-----Compiling Libft\x1b[0m"
	@make -C libft fclean
	@make -C libft
	@echo "\x1b[34m+++++Done Compiling Libft\x1b[0m"
	@echo "\x1b[31m-----Compiling $(NAME)\x1b[0m"
	@$(CC) $(NAME) $(CFLAGS) $(SRC) $(LIBFT) $(HEADER)
	@echo "\x1b[34m+++++Done Compiling $(NAME)\x1b[0m"
	@echo "\x1b[32m+++++Completed All Compiling\x1b[0m"

quick:
	@clear
	@echo "\x1b[31m-----Compiling $(NAME)\x1b[0m"
	@$(CC) $(NAME) $(CFLAGS) $(SRC) $(LIBFT) $(HEADER)
	@echo "\x1b[32m+++++Done Compiling $(NAME)\x1b[0m"

clean:
	@rm $(NAME)
	@echo "\x1b[32m\t+++++Completed Clean\x1b[0m"

fclean: clean
	@make -C libft fclean
	@echo "\x1b[32m\t+++++Completed Full Clean\x1b[0m"

re: fclean all

me:
	@echo ${LOGNAME} > author

norm:
	@clear
	@echo "Starting Norminette, good luck!"
	@norminette $(SRC)
