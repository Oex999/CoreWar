#include <vm.h>

int     check_if_champs_assigned(t_state *state, char **argv)
{
    int i;
    int left;
    
    i = 0;
    left = state->champ_count - state->occupied;
    while (left >= 0 && i < state->champ_count)
    {
        if (state->champ[i] == NULL)
        {
            create_process(state, i + 1, argv[i + 1]);
            left--;
            i++;
        }
        else if (state->champ[i] != NULL)
            i++;
    }
    return (0);
}

int		ft_check_file(t_state *state, char **argv, int count)
{
    int     i;
    int		fd;
    char	*tmp;
    int     cor;
    
    i = 1;
    cor = 0;
    while (i <= count)
    {
        tmp = ft_strrchr(argv[i], '.');
        if (tmp == NULL)
            i++;
        else if (!strcmp(tmp,".cor"))
        {
            if ((fd = open(argv[i], O_RDONLY)) < 0)
                    error_exit(state, "Error: Invalid file at O_RDONLY check\n");
            close(fd);
            cor++;
        }
        i++;
    }
    if (cor < state->champ_count)
        error_exit(state, "Error: Invalid file extension\n");
    return (0);
}

int	parse_dump(t_state *state, char **argv, int i, int count)
{
    int dump_count;
    
    dump_count = 0;
    state->cycles_to_die = CYCLE_TO_DIE;
    while (i <= count)
    {
        if (dump_count != 0)
            error_exit(state, "Error: Only 1 Dump can be entered\n");
        if (!ft_strcmp(argv[i], "-dump"))
        {
            if (ft_atoi(argv[i + 1]) > 0)
            {
                state->dump = ft_atoi(argv[i + 1]);
                dump_count++;
            }
            else if (ft_atoi(argv[i + 1]) <= 0)
                error_exit(state, "Error: Dump  must be greater than zero\n");
        }
        i++;
    }
    return (0);
}

int	parse_champ_number(t_state *state, char **argv, int i, int count)
{
    int         tmp;
    int         n;

    tmp = 0;
    n = 0;
    while (i <= count)
    {
        if (!ft_strcmp(argv[i], "-n"))
        {
            n++;
            tmp = ft_atoi(argv[i + 1]);
            if (tmp <= 0)
                error_exit(state, "Error: position to be assigned cannot be less 0 or less\n");
            else if (tmp <= MAX_PLAYERS && tmp <= state->champ_count)
            {
                if (state->champ[tmp - 1] == NULL)
                    create_process(state, tmp, argv[i + 2]);
                else
                    error_exit(state, "Error: position already assigned\n");
            }
            else if (tmp > MAX_PLAYERS || tmp > state->champ_count)
                error_exit(state, "Error: Attempting to assign postion greater than max players / current players\n");
            i++;
        }
        else if (ft_strcmp(argv[i], "-n"))
            i++;
    }
    state->occupied = n;
    return (0);
}

int	parse_champ_count(t_state *state, char **argv, int count)
{
    int         i;
    int         champs;
    char        *tmp;
    
    i = 1;
    champs = 0;
    while (i <= count)
    {
        tmp = ft_strrchr(argv[i], '.');
        if (!ft_strcmp("-n",argv[i]))
            i++;
        else if (!ft_strcmp("-dump",argv[i]))
            i++;
        else if (ft_strncmp(tmp, ".cor", 3) == 0)
            champs++;
        i++;
    }
    if (champs == 0 || champs > MAX_PLAYERS)
        error_exit(state, "Error: Invalid amount of players\n");
    else if (champs > 0 && champs <= MAX_PLAYERS)
        state->champ_count = champs;
    return (0);
}


void        parse_user_input(t_state *state, char **argv, int count)
{
    int     i;
    
    i = 1;
    parse_champ_count(state, argv, count);
    parse_champ_number(state, argv, i, count);
    parse_dump(state, argv, i, count);
    check_if_champs_assigned(state, argv);
    ft_check_file(state, argv, count);
}
