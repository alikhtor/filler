/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 22:19:05 by alikhtor          #+#    #+#             */
/*   Updated: 2018/06/11 16:05:46 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		ft_surround_enemy_first_time(int x, int y, t_filler *f)
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

static void		ft_find_enemy(t_filler *f)
{
	int			y;
	int			x;

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

static void		ft_free_map_and_token(t_filler *f)
{
	int			y;

	y = 0;
	while (y < f->field_y)
	{
		free(f->bf[y]);
		y++;
	}
	y = 0;
	while (y < f->tkn_y)
	{
		free(f->token[y]);
		y++;
	}
	free(f->bf);
	free(f->token);
	free(f->t_bot);
}

int				main(void)
{
	char		*str;
	int			fd;
	t_filler	*f;

	f = (t_filler*)malloc(sizeof(t_filler));
	get_next_line(fd = 0, &str);
	ft_initialize_enemy_and_bot(str, f);
	free(str);
	while (1)
	{
		f->t_bot = (t_point*)malloc(sizeof(t_point));
		ft_draw_battle_field(fd, f);
		ft_draw_token(fd, f);
		ft_find_enemy(f);
		ft_surround_enemy(f);
		ft_cut_token(f);
		ft_set_token_values(f);
		ft_find_position_for_token(f);
		ft_printf("%d %d\n", f->ret_y, f->ret_x);
		ft_free_map_and_token(f);
		if (f->ret_y == 0 && f->ret_x == 0)
			break ;
	}
	free(f);
	return (0);
}
