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


static 	void display_control(void)
{
	ft_putendl_fd("# # # # # # # # # # # # # # # #", 1);
	ft_putendl_fd("#           Control :         #", 1);
	ft_putendl_fd("#-----------------------------#", 1);
	ft_putendl_fd("# tab : reset default config. #", 1);
	ft_putendl_fd("#  Q  : increase width map.   #", 1);
	ft_putendl_fd("#  E  : ecrease width map.    #", 1);
	ft_putendl_fd("#  W  : move up map.          #", 1);
	ft_putendl_fd("#  S  : move down map.        #", 1);
	ft_putendl_fd("#  A  : move left map.        #", 1);
	ft_putendl_fd("#  D  : move right map.       #", 1);
	ft_putendl_fd("#  E  : increase relief.      #", 1);
	ft_putendl_fd("#  F  : decrease relief.      #", 1);
	ft_putendl_fd("#  H  : decrease size map.    #", 1);
	ft_putendl_fd("#  Y  : increase size map.    #", 1);
	ft_putendl_fd("# # # # # # # # # # # # # # # #", 1);

}
int		main(int ac, char **av)
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
		if (env->error == 1)
			exit(0);
		mlx = init_mlx();
		display_control();
		print_vertical_lines(mlx, env);
		print_horizontal_lines(mlx, env);
		launch_fdf(mlx, env);
		return (0);
	}
	else
		ft_putendl_fd("Invalid number of argument", 2);
}
