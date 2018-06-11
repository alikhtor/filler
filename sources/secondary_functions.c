/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:09:28 by alikhtor          #+#    #+#             */
/*   Updated: 2018/06/11 16:09:31 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		ft_set_token_values(t_filler *f)
{
	f->t_bot->tmp_sum = 0;
	f->t_bot->sum = 100000;
	f->t_bot->bot_touch = 0;
	f->ret_x = 0;
	f->ret_y = 0;
}

void		ft_eraise_tmp_sum(t_filler *f)
{
	f->t_bot->tmp_sum = 0;
	f->t_bot->bot_touch = 0;
}
