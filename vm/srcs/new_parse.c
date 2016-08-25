#include <vm.h>

/*
// If the -dump flag is found, state->dump is set the the parsed value, else it is set to the default value
*/

int	parse_dump(t_state *state, char **argv, int i)
{
    // int         i;
    
    //i = 1;
    state->cycles_to_die = CYCLE_TO_DIE;
    printf("state.cycles_to_die set to default: %i\n", state->cycles_to_die);//debuggery
    //  while (i <= count)
    //  {
    printf("arv[i] in parse_dump = %s\n", argv[i - 2]);
    //if (!ft_strcmp("-dump", argv[i]))
    //{
        printf("\n\tfound: -dump flag\n\n");//debuggery
        printf("dump at argv = %s\n", argv[i - 2]);//debuggery
        if (ft_atoi(argv[i - 2]) > 0)
            state->dump = ft_atoi(argv[i - 2]);
        else
            error_exit(state, "Error: Dump  must be greater than zero\n");
        printf("state.dump is now set to: %i\n", state->dump);//debuggery
        return (0);
    //}
    //  i++;
    // }
    if (state->dump == 0)
        ft_putstr("\n\tno -dump flag found\n\n");
    return (0);
}

/*
// If a -n flag is found, it assigns the player to the player number given
*/

int	parse_champ_number(t_state *state, char **argv, int i)
{
    //int         i;
    //int         n;
    int         tmp;
    
    //i = 1;
    tmp = 0;
    //n = 0;
    printf("at beginning of parse_champ_number, champ_count = %i\n\n", state->champ_count);
    // while (i <= count)
    // {
    //if (!ft_strcmp("-n", argv[i]))
    //{
        printf("\tfound: -n flag\n");//debuggery
        //n++;
        tmp = ft_atoi(argv[i + 1]);
        printf("\nchamp_no to be set = %s\n", argv[i + 1]);//debuggery
        if (tmp <= MAX_PLAYERS && tmp <= state->champ_count)
        {
            if (state->champions[tmp - 1] == NULL)
                create_process(state, tmp);
            else
                error_exit(state, "Error: position already assigned\n");
        }
        else
            error_exit(state, "Error: Attempting to assign postion greater than max players / current players\n");
        printf("state.champion_no is now set to: %i\n", state->champions[tmp - 1]->champion_no);//debuggery
        printf("new champ at %p\n", state->champions[tmp - 1]);//debuggery
    //}
    //   i++;
    // }
    // printf("\nChecking if all champions assigned...\n");
    //  if (n < state->champ_count)
    //{
    //   printf("\t%i champs not assigned yet, checking available slots\n", state->champ_count - n);
    // }
    //check_if_champs_assigned(state, state->champ_count - n);
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
    printf("Initial state.champ_count set to %i\n", state->champ_count);//debuggery
    printf("starting parse_champ_count...\n\n");
    
    parse_champ_count(state, argv, count);
    
    printf("After parse_champ_count call, champ_count = %i\n", state->champ_count);//debuggery
    while (i <= count)
    {
        //printf("\n%s\n", argv[i]);
        if (!ft_strcmp(argv[i], "-n"))
        {
            parse_champ_number(state, &argv[i - 1], i);
            i++;
            
        }
        else if (!ft_strcmp(argv[i], "-dump"))
        {
            printf("value after -dump = %s\n", argv[i + 1]);
            parse_dump(state, &argv[i - 1], i);
            printf("After parse_dump call, state->dump value = %i, and cycles_to_die value = %i\n", state->dump, state->cycles_to_die);//debuggery
        }
        //else
        //    ft_check_file(state, &argv[i]);
        i++;

    }
}