#include <vm.h>
/*
int magic(char **argv, int count)
{
    char *c;
    int i;
    
    i = 1;
    while (i <= count)
    {
        read(argv[i], &c, 8);
        printf("\n\n8 bytes = %s\n\n", c);
        i++;
    }
    return (0);
}
*/

int		ft_check_file(t_state *state, char **argv)
{
    //int     i;
    int		fd;
    char	*tmp;
    
    //i = 1;
    //while (i <= count)
   // {
        tmp = ft_strrchr(*argv, '.');
    printf("\ntmp = %s\n", tmp);
        if (ft_strncmp(tmp, ".cor", 3) != 0)
            error_exit(state, "Error: Invalid file extension at .cor check\n");
        if ((fd = open(*argv, O_RDONLY)) < 0)
            error_exit(state, "Error: Invalid file at O_RDONLY check\n");
        close(fd);
       // i++;
    //}
    printf("\nValid file(s) and extension\n");
    return (0);
}

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
        if (!ft_strcmp("-dump", argv[i]))
        {
            printf("\n\tfound: -dump flag\n\n");//debuggery
            printf("dump at argv = %s\n", argv[i + 1]);//debuggery
            if (ft_atoi(argv[i + 1]) > 0)
                state->dump = ft_atoi(argv[i + 1]);
            else
                error_exit(state, "Error: Dump  must be greater than zero\n");
            printf("state.dump is now set to: %i\n", state->dump);//debuggery
            return (0);
        }
      //  i++;
   // }
    if (state->dump == 0)
        ft_putstr("\n\tno -dump flag found\n\n");
    return (0);
}

/*
// If a .cor extension is found, the champ_count is incremented
*/

int	parse_champ_count(t_state *state, char **argv, int count)
{
    int         i;
    //int         x;
    int         champs;
    char        *tmp;
    
    i = 1;
    //x = 0;
    champs = 0;
    while (i <= count)
    {
        tmp = ft_strrchr(argv[i], '.');
        if (ft_strncmp(tmp, ".cor", 3) == 0)
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

/*
// If a -n flag is found, it assigns the player to the player number given
*/

int	parse_champ_number(t_state *state, char **argv, int i)
{
    //int         i;
    int         n;
    int         tmp;
    
    //i = 1;
    tmp = 0;
    n = 0;
    printf("at beginning of parse_champ_number, champ_count = %i\n\n", state->champ_count);
   // while (i <= count)
   // {
        if (!ft_strcmp("-n", argv[i]))
        {
            printf("\tfound: -n flag\n");//debuggery
            n++;
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
        }
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
    int i;
    int n;
    
    i = 1;
    n = 0;
    while (i <= count)
    {
        if (ft_strcmp(argv[i], "-n") == 0)
        {
            parse_champ_number(state, &argv[i + 1], i);
            
        }
        else if (ft_strcmp(argv[i], "-dump") == 0)
        {
            parse_dump(state, &argv[i + 1], i);
            printf("After parse_dump call, state->dump value = %i, and cycles_to_die value = %i\n", state->dump, state->cycles_to_die);//debuggery
        }
        else
        {
            ft_check_file(state, &argv[i]);
            n++;
        }
        i++;
    }
    printf("Initial state.champ_count set to %i\n", state->champ_count);//debuggery
    parse_champ_count(state, argv, count);
    printf("After parse_champ_count call, champ_count = %i\n", state->champ_count);//debuggery
    if (n < state->champ_count)
    {
        printf("\t%i champs not assigned yet, checking available slots\n", state->champ_count - n);
    }
    check_if_champs_assigned(state, state->champ_count - n);

    printf("Initial state.champ_count set to %i\n", state->champ_count);//debuggery
    parse_champ_count(state, argv, count);
    printf("After parse_champ_count call, champ_count = %i\n", state->champ_count);//debuggery

   // parse_dump(state, argv, count);
    
    write(1, "\n", 1);//debug
    

   // parse_champ_number(state, argv, count);
    //ft_check_file(state, argv, count);
}
