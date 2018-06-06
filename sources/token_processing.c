/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:37:53 by alikhtor          #+#    #+#             */
/*   Updated: 2018/06/06 22:27:06 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		ft_set_token_values(t_filler *f)
{
	f->t_bot->tmp_sum = 0;
	f->t_bot->sum = 100000;
	f->t_bot->bot_touch = 0;
	f->t_bot->ret_x = 0;
	f->t_bot->ret_y = 0;
}

static void	ft_make_zero(t_filler *f)
{
	f->t_bot->tmp_sum = 0;
	f->t_bot->bot_touch = 0;
}

static int	ft_data_recording(int x, int y, t_filler *f)
{
	int		enemy_touch;

	enemy_touch = 0;
	if (f->bf[y][x] == f->bot || f->bf[y][x] == ft_tolower(f->bot))
		f->t_bot->bot_touch++;
	else if (f->bf[y][x] == f->enemy || f->bf[y][x] == ft_tolower(f->enemy))
		enemy_touch++;
	else
		f->t_bot->tmp_sum += (int)f->bf[y][x];
	if (f->t_bot->bot_touch > 1 || enemy_touch)
	{
		ft_make_zero(f);
		return (1);
	}
	else
		return (0);
}

static void	ft_check_token_coordinates(int x, int y, t_filler *f)
{
	int		x_x;
	int		y_y;
	int		tmp_extreme_x;
	int		tmp_extreme_y;
	int		tmp_x;

	tmp_extreme_x = f->extreme_x + x;
	tmp_extreme_y = f->extreme_y + y;
	y_y = 0;
	while (y_y <= f->extreme_y && tmp_extreme_y < f->field_y)
	{
		tmp_x = x;
		x_x = 0;
		while (x_x <= f->extreme_x && tmp_extreme_x < f->field_x)
		{
			if (f->token[y_y][x_x] == '*')
				if (ft_data_recording(tmp_x, y, f))
					return ;
			tmp_x++;
			x_x++;
		}
		y++;
		y_y++;
	}
	if (y >= f->field_y && tmp_extreme_y == f->extreme_y)
		ft_make_zero(f);
}

static void	ft_make_decision(int x, int y, t_filler *f)
{
	if (f->t_bot->bot_touch == 1)
	{
		if (f->t_bot->tmp_sum <= f->t_bot->sum)
		{
			f->t_bot->sum = f->t_bot->tmp_sum;
			f->t_bot->ret_x = x;
			f->t_bot->ret_y = y;
		}
	}
	ft_make_zero(f);
}

void		ft_find_position_for_token(t_filler *f)
{
	int		x;
	int		y;
	int		tmp_extreme_x;
	int		tmp_extreme_y;

	tmp_extreme_x = f->extreme_x;
	tmp_extreme_y = f->extreme_y;
	y = 0;
	while (y < f->field_y && tmp_extreme_y <= f->field_y)
	{
		x = 0;
		while (x < f->field_x && tmp_extreme_x <= f->field_x)
		{
			ft_check_token_coordinates(x, y, f);
			ft_make_decision(x, y, f);
			x++;
			tmp_extreme_x++;
		}
		y++;
		tmp_extreme_x = f->extreme_x;
	}
}
