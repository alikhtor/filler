#include "../includes/filler.h"

int                 ft_is_free_place(t_filler *f)
{
    int x;
    int y;

    y = 0;
    while (y < f->field_y)
    {
        x = 0;
        while (x < f->field_x)
        {
            if (f->bf[y][x] == '.')
                return (1);
            x++;
        }
        y++;
    }
    return (0);
}

static void         ft_surround_enemy_last_time(int x, int y, unsigned char s, t_filler *f)
{
    if (x - 1 >= 0 && f->bf[y][x - 1] == '.')
        f->bf[y][x - 1] = s;
    if (x - 1 >= 0 && y - 1 >= 0 && f->bf[y - 1][x - 1] == '.')
        f->bf[y - 1][x - 1] = s;
    if (x - 1 >= 0 && y + 1 < f->field_y && f->bf[y + 1][x - 1] == '.')
        f->bf[y + 1][x - 1] = s;
    if (y - 1 >= 0 && f->bf[y - 1][x] == '.')
        f->bf[y - 1][x] = s;
    if (y + 1 < f->field_y && f->bf[y + 1][x] == '.')
        f->bf[y + 1][x] = s;
    if (x + 1 < f->field_x && f->bf[y][x + 1] == '.')
        f->bf[y][x + 1] = s;
    if (x + 1 < f->field_x && y + 1 < f->field_y && f->bf[y + 1][x + 1] == '.')
        f->bf[y + 1][x + 1] = s;
    if (x + 1 < f->field_x && y - 1 >= 0 && f->bf[y - 1][x + 1] == '.')
        f->bf[y - 1][x + 1] = s;
}

static void         ft_make_correct_surround(int x, int y, unsigned char s, t_filler *f)
{
    if (f->bf[y][x] == s)
    {
        if (f->bf[y][x] == 'W' || f->bf[y][x] == 'w' || f->bf[y][x] == 'N' || f->bf[y][x] == 'n')
        {
            f->double_increment = 2;
            ft_surround_enemy_last_time(x, y, (unsigned char)(s + 2), f);
        }
        else
            ft_surround_enemy_last_time(x, y, (unsigned char)(s + 1), f);
    }
}

static void         ft_full_surround(t_filler *f)
{
    unsigned char s;
    int x;
    int y;

    s = '0';
    while (ft_is_free_place(f) && s < 255)
    {
        y = 0;
        f->double_increment = 1;
        while (y < f->field_y)
        {
            x = 0;
            while (x < f->field_x)
            {
                ft_make_correct_surround(x, y, s, f);
                x++;
            }
            y++;
        }
        s += f->double_increment;
    }
}

static void         ft_surround_enemy_first_time(int x, int y, t_filler *f)
{
    if (x - 1 >= 0 && f->bf[y][x - 1] == '.')
        f->bf[y][x - 1] = '0';
    if (x - 1 >= 0 && y - 1 >= 0 && f->bf[y - 1][x - 1] == '.')
        f->bf[y - 1][x - 1] = '0';
    if (x - 1 >= 0 && y + 1 < f->field_y && f->bf[y + 1][x - 1] == '.')
        f->bf[y + 1][x - 1] = '0';
    if (y - 1 >= 0 && f->bf[y - 1][x] == '.')
        f->bf[y - 1][x] = '0';
    if (y + 1 < f->field_y && f->bf[y + 1][x] == '.')
        f->bf[y + 1][x] = '0';
    if (x + 1 < f->field_x && f->bf[y][x + 1] == '.')
        f->bf[y][x + 1] = '0';
    if (x + 1 < f->field_x && y + 1 < f->field_y && f->bf[y + 1][x + 1] == '.')
        f->bf[y + 1][x + 1] = '0';
    if (x + 1 < f->field_x && y - 1 >= 0 && f->bf[y - 1][x + 1] == '.')
        f->bf[y - 1][x + 1] = '0';
}

static void         ft_find_enemy_and_surround(t_filler *f)
{
    int             y;
    int             x;

    y = 0;
    while (y < f->field_y)
    {
        x = 0;
        while (x < f->field_x)
        {
            if (f->bf[y][x] == f->enemy || f->bf[y][x] == ft_tolower(f->enemy))
                ft_surround_enemy_first_time(x, y, f);
            x++;
        }
        y++;
    }
}

static void         ft_draw_token(int fd, t_filler *f)
{
    char    *str;
    int     i;

    get_next_line(fd, &str);
    f->tkn_y = ft_atoi(str + 6);
    f->tkn_x = ft_atoi(str + 6 + ft_strlen(ft_itoa(f->tkn_y)));
    f->token = (char**)malloc(sizeof(char*) * (f->tkn_y + 1));
    f->token[f->tkn_y] = 0;
    free(str);
    i = 0;
    while (i < f->tkn_y)
    {
        get_next_line(fd, &str);
        f->token[i] = ft_strdup(str);
        free(str);
        i++;
    }
}

static void         ft_draw_battle_field(int fd, t_filler *f)
{
    char    *str;
    int     i;

    get_next_line(fd, &str);
    f->field_y = ft_atoi(str + 8);
    f->field_x = ft_atoi(str + 8 + ft_strlen(ft_itoa(f->field_y)));
    f->bf = (char**)malloc(sizeof(char*) * (f->field_y + 1));
    f->bf[f->field_y] = 0;
    free(str);
    get_next_line(fd, &str);
    free(str);
    i = 0;
    while (i < f->field_y)
    {
        get_next_line(fd, &str);
        f->bf[i] = ft_strdup(str + 4);
        free(str);
        i++;
    }
}

static void     ft_initialize_bot_and_enemy(char const *str, t_filler *f)
{
    f->bot = (str[10] == '1') ? (char) 'O' : (char) 'X';
    f->enemy = (f->bot == 'O') ? (char) 'X' : (char) 'O';
}

int             main(void)
{
	char        *str;
	int         fd;
	t_filler    *f;

	f = (t_filler*)malloc(sizeof(t_filler));
	fd = open("/Users/alikhtor/Desktop/filler/test1", O_RDONLY);
	get_next_line(fd, &str);
	ft_initialize_bot_and_enemy(str, f);
	free (str);
    while (1)
    {
        ft_draw_battle_field(fd, f);
        ft_draw_token(fd, f);
        ft_find_enemy_and_surround(f);
        ft_full_surround(f);
        break ;
    }
    fd = 0;
    ft_printf("THE MAP IS:\n");
    while (fd < f->field_y) {
        ft_printf("%s\n", f->bf[fd]);
        fd++;
    }
    fd = 0;
    ft_printf("THE TOKEN IS:\n");
    while (fd < f->tkn_y) {
        ft_printf("%s\n", f->token[fd]);
        fd++;
    }
        //fd = open("/Users/alikhtor/Desktop/filler/test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	//dprintf(fd, "work =\n%s\n", str);
    free(f);
	return (0);
}