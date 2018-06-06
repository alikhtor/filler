/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:36:10 by alikhtor          #+#    #+#             */
/*   Updated: 2018/06/06 22:20:53 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	ft_last_y(t_filler *f)
{
	int		x;
	int		y;
	int		tmp_y;

	tmp_y = 0;
	y = 0;
	while (y < f->tkn_y)
	{
		x = 0;
		while (x < f->tkn_x)
		{
			if (f->token[y][x] == '*')
			{
				if (tmp_y < y)
					tmp_y = y;
			}
			x++;
		}
		y++;
	}
	return (tmp_y);
}

static int	ft_last_x(t_filler *f)
{
	int		x;
	int		y;
	int		tmp_x;

	tmp_x = 0;
	y = 0;
	while (y < f->tkn_y)
	{
		x = 0;
		while (x < f->tkn_x)
		{
			if (f->token[y][x] == '*')
			{
				if (tmp_x < x)
					tmp_x = x;
			}
			x++;
		}
		y++;
	}
	return (tmp_x);
}

void		ft_cut_token(t_filler *f)
{
	f->extreme_y = ft_last_y(f);
	f->extreme_x = ft_last_x(f);
}
