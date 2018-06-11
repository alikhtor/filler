/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiaize_and_draw.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:24:37 by alikhtor          #+#    #+#             */
/*   Updated: 2018/06/11 16:07:01 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		ft_draw_token(int fd, t_filler *f)
{
	char	*str;
	char	*step;
	int		i;

	get_next_line(fd, &str);
	f->tkn_y = ft_atoi(str + 6);
	step = ft_itoa(f->tkn_y);
	f->tkn_x = ft_atoi(str + 6 + ft_strlen(step));
	ft_strdel(&step);
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

void		ft_draw_battle_field(int fd, t_filler *f)
{
	char	*str;
	char	*step;
	int		i;

	get_next_line(fd, &str);
	f->field_y = ft_atoi(str + 8);
	step = ft_itoa(f->field_y);
	f->field_x = ft_atoi(str + 8 + ft_strlen(step));
	ft_strdel(&step);
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

void		ft_initialize_enemy_and_bot(char const *str, t_filler *f)
{
	f->bot = (str[10] == '1') ? (char)'O' : (char)'X';
	f->enemy = (f->bot == 'O') ? (char)'X' : (char)'O';
}
