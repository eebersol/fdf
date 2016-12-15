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
	t_env *env;
	t_mlx *mlx;

	if (ac == 2)
	{
		init_env();
		env = recover_env();
		env->file_name = av[1];
		read_file(env);
		parse(env);
		mlx = init_mlx();;
		print_vertical_lines(mlx, env);
		print_horizontal_lines(mlx, env);
		mlx_loop(mlx->mlx);
		return (0);
	}
	else
		ft_putendl_fd("Invalid number of argument", 2);
}
