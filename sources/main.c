/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:02:43 by alikhtor          #+#    #+#             */
/*   Updated: 2018/06/02 15:22:46 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void     ft_draw_battle_field(t_filler *f)
{
    char        *str;
    int         i;

    get_next_line(0, &str);
    f->field_y = ft_atoi(str + 8);
    f->field_x = ft_atoi(str + 8 + ft_strlen(ft_itoa(f->field_y)));
    f->bf = (char **)malloc(sizeof(char *) * (f->field_y + 1));
    f->bf[f->field_y] = NULL;
    free(str);
    get_next_line(0, &str);
    free(str);
    i = 0;
    while (get_next_line(0, &str) && i < f->field_y)
    {
        f->bf[i++] = ft_strdup(str + 4);
        free(str);
    }
}

int             main(void)
{
    char *str;
    t_filler *f;

    f = (t_filler *) malloc(sizeof(*f));
    get_next_line(0, &str);
    f->player = (str[10] == '1') ? (char) 'O' : (char) 'X';
    free(str);
    while (1)
    {
        ft_draw_battle_field(f);
	    //ft_printf("%d %d\n", 8, 2);

        //break;
    }
    return (0);
}
