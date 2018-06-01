/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:02:43 by alikhtor          #+#    #+#             */
/*   Updated: 2018/06/01 09:21:11 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
#include <fcntl.h>

int			main(void)
{
	char	*str;
	int		fd;
	
	get_next_line(0, &str);
	fd = open("/Users/alikhtor/Desktop/filler/test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	dprintf(fd, "work =\n%s\n", str);
	return (0);
}
