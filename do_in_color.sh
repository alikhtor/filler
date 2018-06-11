# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    do_in_color.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/11 16:25:56 by alikhtor          #+#    #+#              #
#    Updated: 2018/06/11 17:14:27 by alikhtor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

red=$(printf "\e[41m\e[30mO\e[0m")
blue=$(printf "\e[44m\e[30mx\e[0m")
light_red=$(printf "\e[101m\e[30mo\e[0m")
light_blue=$(printf "\e[104m\e[30mX\e[0m")
green=$(printf "\e[42m\e[97mplayer\e[0m")

sed "s|o|$light_red|g" |
sed "s|O|$red|g" |
sed "s|X|$light_blue|g" |
sed "s|x|$blue|g" |
sed "s|fin|$green|g"
