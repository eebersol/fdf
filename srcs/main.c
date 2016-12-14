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


static void	run_fdf(t_mlx *mlx, t_env *env)
{
	t_data		data;

	data.mlx = mlx;
	data.env = env;
	mlx_loop(mlx->mlx);
}

int main(int ac, char **av)
{
	t_env *env;
	t_mlx *mlx;

	if (ac == 2)
	{
		init_env();
		env = recover_env();
		env->file_name = av[1];
		read_file();
		parse();
		mlx = init_mlx();;
		draw_vertical_lines(mlx, env);
		draw_horizontal_lines(mlx, env);
		run_fdf(mlx, env);
		return (0);
	}
	else
		ft_putendl_fd("Invalid number of argument", 2);
}