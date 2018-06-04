/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:02:18 by alikhtor          #+#    #+#             */
/*   Updated: 2018/06/01 09:59:58 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libftprintf/includes/ft_printf.h"

typedef struct  s_point
{
    int         ret_x;
    int         ret_y;
    int         sum;
    int         tmp_sum;
    int         bot_touch;
}               t_point;

typedef struct	s_filler
{
	char		**bf;
    char        **token;
    char        bot;
	char 		enemy;
    int 		double_increment;
    int         field_x;
    int         field_y;
    int         tkn_x;
    int         tkn_y;
    int         extreme_x;
    int         extreme_y;
	t_point     *t_bot;
}				t_filler;


#endif
