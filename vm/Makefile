NAME= corewar

CC= gcc -g -o
CFLAGS= -Wall -Werror -Wextra
LIBFT= -L ../libft/ -lft
HEADER= -I ../libft -I include

SP= ./srcs/
SRC= $(SP)corewar.c\
	 $(SP)init.c\
	 $(SP)ft_itoabase.c\
	 $(SP)free.c\
	 $(SP)parsing.c\
	 $(SP)read.c\
	 $(SP)exit.c\
	 $(SP)gamecycles.c\
	 $(SP)gamechamps.c\
	 $(SP)cmd1.c\
	 $(SP)cmd2.c\
	 $(SP)cmd3.c\
	 $(SP)cmd4.c\


all: $(NAME)

$(NAME):
	@clear
	@echo "\x1b[31m-----Compiling Libft\x1b[0m"
	@make -C ../libft fclean
	@make -C ../libft
	@echo "\x1b[34m-----Done Compiling Libft\x1b[0m"
	@echo "\x1b[31m-----Compiling $(NAME)\x1b[0m"
	@$(CC) $(NAME) $(CFLAGS) $(SRC) $(LIBFT) $(HEADER)
	@echo "\x1b[34m-----Done Compiling $(NAME)\x1b[0m"
	@echo "\x1b[32m-----Finished All Compiling\x1b[0m"

quick:
	@clear
	@echo "\x1b[31m-----Compiling $(NAME)\x1b[0m"
	@$(CC) $(NAME) $(CFLAGS) $(SRC) $(LIBFT) $(HEADER)
	@echo "\x1b[34m-----Done Compiling $(NAME)\x1b[0m"

clean:
	@rm $(NAME)
	@echo "\x1b[32mCompleted Clean\x1b[0m"

fclean: clean
	@make -C ../libft fclean
	@echo "\x1b[32mCompleted Full Clean\x1b[0m"

re: fclean all

me:
	@echo "sallen\nbsaunders\nghavenga\noexall" > author

norm:
	@clear
	@echo "Starting Norminette Good Luck."
	@norminette $(SRC)
