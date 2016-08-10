# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghavenga <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/04 07:37:46 by ghavenga          #+#    #+#              #
#    Updated: 2016/08/10 12:35:22 by oexall           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= asm

CC= gcc -o
CFLAGS= -Wall -Werror -Wextra
LIBFT= -L ../libft/ -lft
HEADER= -I ./include -I ../libft

SP= ./srcs/
SRC=	$(SP)assembler.c $(SP)ft_err.c $(SP)ft_check_file.c \
		$(SP)ft_read_file.c $(SP)ft_input_new.c $(SP)ft_input_push.c \
		$(SP)ft_input_free.c $(SP)op.c $(SP)ft_itoa_base.c $(SP)ft_validate.c \
		$(SP)ft_output_free.c $(SP)ft_output_new.c $(SP)ft_output_push.c \
		$(SP)ft_process_input.c \
		$(SP)ft_val_prog.c $(SP)ft_val_comment.c $(SP)ft_val_label.c \
		$(SP)ft_val_cmd.c $(SP)ft_print_file.c $(SP)ft_print_name.c

all: $(NAME)

$(NAME):
	@clear
	@echo "\x1b[31m-----Compiling Libft\x1b[0m"
	@make -C ../libft fclean
	@make -C ../libft
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
	@make -C ../libft fclean
	@echo "\x1b[32m\t+++++Completed Full Clean\x1b[0m"

re: fclean all

me:
	@echo ${LOGNAME} > author

norm:
	@clear
	@echo "Starting Norminette, good luck!"
	@norminette $(SRC)
