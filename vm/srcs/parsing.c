#include <vm.h>

/*
// If the -dump flag is found, cycles_to_die is set the the parsed value, else it is set to the default value
*/

int	parse_cycles_to_die(t_state *state, char **argv, int count)
{
    int         i;
    
    i = 1;
    while (i <= count)
    {
        if (!ft_strcmp("-dump", argv[i]))
        {
            printf("\n\tfound: -dump flag\n\n");//debuggery
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
        ft_putstr("\n\tno -dump flag found\n\n");
        printf("state.cycles_to_die set to default: %i\n", state->cycles_to_die);//debuggery
    }
    return (0);
}

/*
// If a .cor extension is found, the champ_count is incremented
*/

int	parse_champ_count(t_state *state, char **argv, int count)
{
    int         i;
    int         x;
    int         champs;
    char        *c;
    
    i = 1;
    x = 0;
    champs = state->champ_count;
    while (i <= count)
    {
        c = argv[i];
        while (c[x] != '\0')
        {
            if (c[x] == '.' && c[x + 1] == 'c' && c[x + 2 == 'o'] && c[x + 3] == 'r')
            {
                printf("\tfound: .cor flag\n");//debuggery
                champs++;
            }
            x++;
        }
        x = 0;
        i++;
    }
    printf("\nnumber of champions = %i \n", champs);//debuggery
    if (champs > 0 && champs <= MAX_PLAYERS)
    {
        state->champ_count = champs;
        printf("state.champ_count is now set to: %i\n", state->champ_count);//debuggery
    }
    else if (champs > MAX_PLAYERS)
    {
        ft_putstr("Error: max players is 4\n");
        exit(-1);
    }
        
    return (0);
}

/*
// If a -n flag is found, it assigns the player to the player number given
*/

int	parse_champ_number(t_state *state, char **argv, int count)
{
    int         i;
    int         n;
    int         tmp;
    
    i = 1;
    tmp = 0;
    n = 0;
    printf("at beginning of parse_champ_number, champ_count = %i\n\n", state->champ_count);
    while (i <= count)
    {
        if (!ft_strcmp("-n", argv[i]))
        {
            printf("\tfound: -n flag\n");//debuggery
            n++;
            tmp = ft_atoi(argv[i + 1]);
            printf("\nchamp_no to be set = %s\n", argv[i + 1]);//debuggery
            if (tmp <= MAX_PLAYERS)
            {
                if (state->champions[tmp -1] == NULL)
                    create_process(state, tmp);
                else
                {
                    ft_putstr("position already assigned");
                    exit(-1);
                }
            }
            else
            {
                ft_putstr("Error: Max Players is 4 and attempting to assign player to player number ");
                ft_putnbr(tmp);
                exit(-1);
            }
            printf("state.champion_no is now set to: %i\n", state->champions[tmp - 1]->champion_no);//debuggery
            printf("new champ at %p\n", state->champions[tmp - 1]);//debuggery
        }
        i++;
    }
    printf("\nChecking if all champions assigned...\n");
    if (n < state->champ_count)
    {
        printf("\t%i champs not assigned yet, checking available slots\n", state->champ_count - n);
    }
    check_if_champs_assigned(state, state->champ_count - n);
    return (0);
}

/*
// Checks if all players assigned a slot by comparing number of -n flags vs number of .cor flags
*/

int     check_if_champs_assigned(t_state *state, int left)
{
    int i;
    int x;
    
    x = 0;
    i = 1;
    while (i <= left && x < state->champ_count)
    {
        printf("\n\tchecking if state->champions[%i] is available...", x);
        if (state->champions[x] == NULL)
        {
            printf("\n\tavailable... assigning\n");
            create_process(state, x + 1);
            i++;
            x++;
        }
        else
        {
            printf("\n\toccupied...");
            x++;
        }
    }
    printf("\nAll champs have a room...\n");
    return (0);
}

/*
// Checks argv for -n, -dump flags and number of .cor files
*/

void    parse_user_input(t_state *state, char **argv, int count)
{
    parse_champ_count(state, argv, count);
    printf("After parse_champ_count call, champ_count = %i\n", state->champ_count);//debuggery

    parse_cycles_to_die(state, argv, count);
    printf("After parse_cycles_to_die call, cycles_to_die value = %i\n", state->cycles_to_die);//debuggery
    write(1, "\n", 1);//debug
    
    printf("Initial state.champ_count set to %i\n", state->champ_count);//debuggery
    parse_champ_number(state, argv, count);
}
