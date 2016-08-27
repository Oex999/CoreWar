#include <vm.h>

int     check_if_champs_assigned(t_state *state)
{
    int i;
    int left;
    
    i = 0;
    printf("starting check_if_champs_assigned...\n\n");
    left = state->champ_count - state->occupied;
    printf("\nUnassigned Players = %i\n", left);
    printf("\n\nStarting check_if_champ_assigned...\n\n");
    while (left >= 0 && i < state->champ_count)
    {
        printf("\n\tchecking if state->champions[%i] is available...\n\n", i);
        if (state->champions[i] == NULL)
        {
            printf("\navailable...\n");
            create_process(state, i + 1);
            left--;
            i++;
            printf("Unasigned champ value decreased in open = %i\n", left);
        }
        else if (state->champions[i] != NULL)
        {
            i++;
            printf("Taken...\n");
            printf("i value incresed in taken = %i\n", i);
        }

    }
    printf("i value = %i\n", i);
    printf("\nAll champs have a room...\n");
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
    printf("\nStarting check_file...\n\n");
    while (i <= count)
    {
        tmp = ft_strrchr(argv[i], '.');
        printf("tmp is set to %s\n", tmp);
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
    printf("\nValid .cor count = %i\n", cor);
    if (cor < state->champ_count)
        error_exit(state, "Error: Invalid file extension\n");
    printf("\nValid file(s) and extension\n");
    return (0);
}

/*
// If the -dump flag is found, state->dump is set the the parsed value, else it is set to the default value
*/

int	parse_dump(t_state *state, char **argv, int i, int count)
{
    int dump_count;
    
    dump_count = 0;
    printf("\n\nstarting parse_dump...\n\n");
    state->cycles_to_die = CYCLE_TO_DIE;
    printf("state.cycles_to_die set to default: %i\n", state->cycles_to_die);//debuggery
    while (i <= count)
    {
        if (dump_count != 0)
            error_exit(state, "Error: Only 1 Dump can be entered\n");
        printf("argv[%i] in parse_dump = %s\n", i, argv[i]);
        if (!ft_strcmp(argv[i], "-dump"))
        {
            printf("\n\tfound: -dump flag\n\n");//debuggery
            printf("dump at argv[%i] = %s\n", i + 1, argv[i + 1]);//debuggery
            if (ft_atoi(argv[i + 1]) > 0)
            {
                state->dump = ft_atoi(argv[i + 1]);
                dump_count++;
                printf("state.dump is now set to: %i\n", state->dump);//debuggery
            }
            else if (ft_atoi(argv[i + 1]) <= 0)
                error_exit(state, "Error: Dump  must be greater than zero\n");
        }
        i++;
    }
    if (state->dump == 0)
        ft_putstr("\n\tno -dump flag found\n\n");
    return (0);
}

/*
// If a -n flag is found, it assigns the player to the player number given
*/

int	parse_champ_number(t_state *state, char **argv, int i, int count)
{
    int         tmp;
    int         n;

    tmp = 0;
    n = 0;
    printf("\nstarting parse_champ_number...\n\n");
    printf("at beginning of parse_champ_number, champ_count = %i\n\n", state->champ_count);
    while (i <= count)
    {
        if (!ft_strcmp(argv[i], "-n"))
        {
            n++;
            printf("\tfound: -n flag at argv[%i]\n", i);//debuggery
            tmp = ft_atoi(argv[i + 1]);
            if (tmp <= 0)
                error_exit(state, "Error: position to be assigned cannot be less 0 or less\n");
            else if (tmp <= MAX_PLAYERS && tmp <= state->champ_count)
            {
                if (state->champions[tmp - 1] == NULL)
                    create_process(state, tmp);
                else
                    error_exit(state, "Error: position already assigned\n");
            }
            else if (tmp > MAX_PLAYERS || tmp > state->champ_count)
                error_exit(state, "Error: Attempting to assign postion greater than max players / current players\n");
            printf("tmp is set to %i\n", tmp);
            printf("\nchamp_no to be set = %s\n", argv[i + 1]);//debuggery
            i++;
        }
        else if (ft_strcmp(argv[i], "-n"))
        {
            printf("no -n found at argv[%i]\n", i);
            i++;
        }
    }
    state->occupied = n;
    if (n >= 1)
    {
        printf("state.champion_no is now set to: %i\n", state->champions[tmp - 1]->champion_no);//debuggery
        printf("new champ at %p\n", state->champions[tmp - 1]);//debuggery
    }
    else
        printf("no -n flags found\n\n");
    return (0);
}

/*
// If a .cor extension is found, the champ_count is incremented
*/

int	parse_champ_count(t_state *state, char **argv, int count)
{
    int         i;
    int         champs;
    char        *tmp;
    
    i = 1;
    champs = 0;
    printf("starting parse_champ_count...\n\n");
    while (i <= count)
    {
        tmp = ft_strrchr(argv[i], '.');
        if (!ft_strcmp("-n",argv[i]))
            i++;
        else if (!ft_strcmp("-dump",argv[i]))
            i++;
        else if (ft_strncmp(tmp, ".cor", 3) == 0)
        {
            printf("\tfound: champion\n");//debuggery
            champs++;
        }
        i++;
    }
    printf("\nnumber of champions = %i \n", champs);//debuggery
    if (champs == 0 || champs > MAX_PLAYERS)
        error_exit(state, "Error: Invalid amount of players\n");
    else if (champs > 0 && champs <= MAX_PLAYERS)
    {
        state->champ_count = champs;
        printf("state.champ_count is now set to: %i\n", state->champ_count);//debuggery
    }
    return (0);
}


void        parse_user_input(t_state *state, char **argv, int count)
{
    int     i;
    
    i = 1;
    printf("starting parse_user_input...\n\n");
    
    printf("Initial state.champ_count set to %i\n", state->champ_count);//debuggery
    parse_champ_count(state, argv, count);
    printf("After parse_champ_count call, champ_count = %i\n", state->champ_count);//debuggery
    
    parse_champ_number(state, argv, i, count);
    
    parse_dump(state, argv, i, count);

    check_if_champs_assigned(state);
    ft_check_file(state, argv, count);
}
