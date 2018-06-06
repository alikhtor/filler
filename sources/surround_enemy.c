/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surround_enemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:23:06 by alikhtor          #+#    #+#             */
/*   Updated: 2018/06/05 15:51:37 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int			ft_dots_in_bf(t_filler *f)
{
	int				x;
	int				y;

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

static void			ft_surround_enemy_last_time(int x, int y,\
		unsigned char s, t_filler *f)
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

static void			ft_make_correct_surround(int x, int y,\
		unsigned char s, t_filler *f)
{
	if (f->bf[y][x] == s)
	{
		if (f->bf[y][x] == 'W' || f->bf[y][x] == 'w' ||\
				f->bf[y][x] == 'N' || f->bf[y][x] == 'n')
		{
			f->double_increment = 2;
			ft_surround_enemy_last_time(x, y, (unsigned char)(s + 2), f);
		}
		else
			ft_surround_enemy_last_time(x, y, (unsigned char)(s + 1), f);
	}
}

void				ft_surround_enemy(t_filler *f)
{
	unsigned char	s;
	int				x;
	int				y;

	s = '0';
	while (ft_dots_in_bf(f) && s < 255)
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
