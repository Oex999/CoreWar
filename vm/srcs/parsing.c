#include <vm.h>

int	parse_cycles_to_die(t_state *state, char **argv, int count)
{
    int         i;
    
    i = 1;
    while (i <= count)
    {
        if (!ft_strcmp("-dump", argv[i]))
        {
            printf("\tfound: -dump flag\n");//debuggery
            printf("cycles to die at argv = %s\n", argv[i + 1]);//debuggery
            state->cycles_to_die = ft_atoi(argv[i + 1]);
            printf("state.cycles_to_die is now set to: %i\n", state->cycles_to_die);//debuggery
            return (0);
        }
        i++;
    }
    if (state->cycles_to_die == 0)
    {
        state->cycles_to_die = CYCLE_TO_DIE;
        ft_putstr("no -dump flag found\n");
        printf("state.cycles_to_die set to default: %i\n", state->cycles_to_die);//debuggery
    }
    return (0);
}

int	parse_champ_count(t_state *state, char **argv, int count)
{
    int         i;
    int         x;
    int         champs;
    char        *champion;
    
    i = 1;
    x = 0;
    champs = state->champ_count;
    while (i <= count)
    {
        champion = argv[i];
        while (champion[x] != '\0')
        {
            if (champion[x] == '.' && champion[x + 1] == 'c' && champion[x + 2 == 'r'])
            {
                printf("\tfound: .cor flag\n");//debuggery
                champs++;
            }
            x++;
        }
        x = 0;
        i++;
    }
    printf("number of champions = %i \n", champs);//debuggery
    if (champs > 0 && champs <= MAX_PLAYERS)
    {
        state->champ_count = champs;
        printf("state.champ_count is now set to: %i\n", state->champ_count);//debuggery
    }
    else if (champs > MAX_PLAYERS)
    {
        ft_putstr("Error: max players is 4");
    }
        
    return (0);
}

int	parse_champ_number(t_state *state, char **argv, int count)
{
    int         i;
    int         tmp;
    
    i = 1;
    tmp = 0;
    while (i <= count)
    {
        if (!ft_strcmp("-n", argv[i]))
        {
            printf("\tfound: -n flag\n");//debuggery
            tmp = ft_atoi(argv[i + 1]);
            printf("champ_no at argv = %s\n", argv[i + 1]);//debuggery

            printf("champ_no at tmp = %i\n", tmp);//debuggery
            create_process(state, tmp);
            //state->champions[tmp - 1]->champion_no = tmp;
            printf("state.champion_no is now set to: %i\n", state->champions[tmp - 1]->champion_no);//debuggery
            printf("new champ at %p\n", state->champions[tmp - 1]);//debuggery

            return (0);
        }
        i++;
    }
    return (0);
}

void    parse_user_input(t_state *state, char **argv, int count)
{
    parse_cycles_to_die(state, argv, count);
    printf("After parse_cycles_to_die call, cycles_to_die value = %i\n", state->cycles_to_die);//debuggery
    write(1, "\n", 1);//debug
    printf("Initial state.champ_count set to %i\n", state->champ_count);//debuggery
    parse_champ_count(state, argv, count);
    printf("After parse_champ_count call, champ_count = %i\n", state->champ_count);//debuggery
    parse_champ_number(state, argv, count);
    printf("after parse_champ_number, champ_number = %i\n", state->champions[0]->champion_no);

}
