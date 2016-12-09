/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:32:29 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/26 13:06:04 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	if (ac == 2)
	{
		init_env();
		printf("1 [%f]\n", recover_env()->height);
		parse_map(av[1]);
		print_map();
		return (0);
	}
	else
		ft_putendl_fd("Invalid number of argument", 2);
}