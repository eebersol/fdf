/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parse_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:32:29 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/26 13:06:04 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

#0C9D40
#1DA742
#2FB244
#41BD46
#64D34A
#76DE4C
#76DE4C


unsigned int 	pick_color(int i)
{
	int *begin_color;
	int *add_color;

	begin_color = (int*)malloc(sizeof(int) * 3);
	add_color = (int*)malloc(sizeof(int) * 3);
	begin_color[0] = 51;
	begin_color[1] = 255;
	begin_color[2] = 0;
	add_color[0] = 51;
	add_color[1] = 255 - i;
	add_color[2] = 0 + i;
	printf("%s\n", ft_itoa_base(add_color[0], 10));
	return (0);


}